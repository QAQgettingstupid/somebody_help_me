import java.util.Scanner;
import java.util.HashMap;
import java.util.Stack;
import java.util.Map;

//作者:蔡芳宇
//學號:111216019
//自評:20%+60%+20%

public class H5_111216019 {
    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        Map<Character, Integer> priority = new HashMap<>();
        priority.put('(', 0);
        priority.put('-', 1);
        priority.put('+', 1);
        priority.put('/', 2);
        priority.put('*', 2);

        System.out.println("please enter expression: ");

        while (scn.hasNext()) {
            String input = scn.nextLine();
            Stack<Character> operator = new Stack<>();
            Stack<Integer> operand = new Stack<>();
            int index = 0, temp_num = 0;
            boolean negative = false, devide_0 = false;

            // 逐個讀取輸入字元
            while (index < input.length()) {
                if (input.charAt(index) <= '9' && input.charAt(index) >= '0') {
                    temp_num *= 10;
                    temp_num += input.charAt(index) - '0';
                } else if (input.charAt(index) == '+' || input.charAt(index) == '-' || input.charAt(index) == '*'
                        || input.charAt(index) == '/' || input.charAt(index) == '(' || input.charAt(index) == ')') {

                    // 放入數字
                    if (temp_num != 0) {
                        if (negative) {
                            operand.push(temp_num * (-1));
                            negative = false;
                        } else
                            operand.push(temp_num);
                        temp_num = 0;
                    }

                    // 負號
                    if (input.charAt(index) == '-'
                            && (index == 0
                                    || (index - 1 >= 0
                                            && (input.charAt(index - 1) == '+' || input.charAt(index - 1) == '('
                                                    || input.charAt(index - 1) == '*' || input.charAt(index - 1) == '-'
                                                    || input.charAt(index - 1) == '/')))) {
                        negative = true;
                        index++;
                        continue;
                    }

                    // 左括弧(7+23)*(3-1)/(3+7)
                    if (input.charAt(index) == '(')
                        operator.push(input.charAt(index));

                    // 右括弧
                    else if (input.charAt(index) == ')') {

                        // 對operator裡在'('之前的運算子進行運算
                        while (!devide_0 && operator.peek() != '(') {
                            try {
                                operand.push(count(operand, operator.peek()));
                            } catch (ArithmeticException e) {
                                System.out.println("Division by zero is not allowed.");
                                devide_0 = true;
                                break;
                            }
                            operator.pop();
                        }
                        operator.pop();
                    }

                    else {

                        // 輸入優先權小於等於stack top,先pop進行運算
                        while (!devide_0 && !operator.empty()
                                && priority.get(operator.peek()) >= priority.get(input.charAt(index))) {
                            try {
                                operand.push(count(operand, operator.peek()));
                            } catch (ArithmeticException e) {
                                System.out.println("Division by zero is not allowed.");
                                devide_0 = true;
                                break;
                            }
                            operator.pop();
                        }
                        operator.push(input.charAt(index));
                    }
                }
                index++;
            }
            if (temp_num != 0)
                if (negative) {
                    operand.push(temp_num * (-1));
                    negative = false;
                } else
                    operand.push(temp_num);

            // 檢查是否還有運算子尚未運算
            while (!devide_0 && !operator.empty()) {
                try {
                    operand.push(count(operand, operator.peek()));
                } catch (ArithmeticException e) {
                    System.out.println("Division by zero is not allowed.");
                    devide_0 = true;
                    break;
                }
                operator.pop();
            }

            if (!devide_0) {
                System.out.println(operand.peek());
                operand.pop();
            }
            System.out.println();
            System.out.println("please enter expression: ");
        }
    }

    // 運算函式實作
    public static Integer count(Stack<Integer> s, Character c) throws ArithmeticException {
        int result = 0;
        int back = s.peek();
        s.pop();
        int front = s.peek();
        s.pop();

        switch (c) {
            case '+':
                result = front + back;
                break;
            case '-':
                result = front - back;
                break;
            case '*':
                result = front * back;
                break;
            case '/':
                result = front / back;
                break;
        }
        return result;
    }
}
