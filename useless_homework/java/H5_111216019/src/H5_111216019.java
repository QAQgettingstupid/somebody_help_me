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
            Stack<Double> operand = new Stack<>();
            Double temp_num;
            int index = 0, numfront = 0;
            boolean negative = false, devide_0 = false, changed = false;

            // 逐個讀取輸入字元
            while (index < input.length()) {
                if (changed == false
                        && (input.charAt(index) == '.' || (input.charAt(index) <= '9' && input.charAt(index) >= '0'))) {
                    numfront = index;
                    changed = true;
                } else if (input.charAt(index) == '+' || input.charAt(index) == '-' || input.charAt(index) == '*'
                        || input.charAt(index) == '/' || input.charAt(index) == '(' || input.charAt(index) == ')') {

                    // 放入數字
                    if (changed) {
                        temp_num = Double.parseDouble(input.substring(numfront, index));
                        System.out.println("numfront= " + numfront);
                        System.out.printf("input num=%.1f\n", temp_num);
                        if (negative) {
                            operand.push(temp_num * (-1));
                            negative = false;
                        } else
                            operand.push(temp_num);
                        changed = false;
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

                            //try catch限整數需要
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
            if (changed) {
                temp_num = Double.parseDouble(input.substring(numfront, index));
                if (negative) {
                    operand.push(temp_num * (-1));
                    negative = false;
                } else
                    operand.push(temp_num);
            }

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
    public static Double count(Stack<Double> s, Character c) throws ArithmeticException {
        Double result = 0.0;
        Double back = s.peek();
        s.pop();
        Double front = s.peek();
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
