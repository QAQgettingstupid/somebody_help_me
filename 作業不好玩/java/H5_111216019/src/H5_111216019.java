import java.util.Scanner;
import java.util.HashMap;
import java.util.Stack;
import java.util.Map;


//作者:蔡芳宇
//學號:111216019
//自評:20%+60%+20% (不支援負數運算)

public class H5_111216019 {
    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        Map<Character, Integer> priority = new HashMap<>();
        priority.put('(', 0);
        priority.put('-', 1);
        priority.put('+', 1);
        priority.put('/', 2);
        priority.put('*', 2);

        while (scn.hasNext()) {
            String imput = scn.nextLine();
            Stack<Character> operator = new Stack<>();
            Stack<Integer> operand = new Stack<>();
            int index = 0, temp_num = 0;

            // System.out.println(imput);

            // 逐個讀取輸入字元
            while (index < imput.length()) {
                if (imput.charAt(index) <= '9' && imput.charAt(index) >= '0') {
                    temp_num *= 10;
                    temp_num += imput.charAt(index) - '0';
                } else if (imput.charAt(index) == '+' || imput.charAt(index) == '-' || imput.charAt(index) == '*'
                        || imput.charAt(index) == '/') {

                    // 放入數字
                    if (temp_num != 0) {
                        operand.push(temp_num);
                        temp_num = 0;
                    }

                    // 左括弧(7+23)*(3-1)/(3+7)
                    if (imput.charAt(index) == '(')
                        operator.push(imput.charAt(index));

                    // 右括弧
                    else if (imput.charAt(index) == ')') {

                        // 對operator裡在'('之前的運算子進行運算
                        while (operator.peek() != '(') {
                            operand.push(count(operand, operator.peek()));
                            System.out.println("now top-> " + operand.peek());
                            operator.pop();
                        }
                        operator.pop();
                    }

                    // 都還沒實作,負數辨認也還沒搞
                    else {

                        // 輸入優先權小於等於stack top,先pop進行運算
                        while (!operator.empty()
                                && priority.get(operator.peek()) >= priority.get(imput.charAt(index))) {
                            operand.push(count(operand, operator.peek()));
                            System.out.println("now top-> " + operand.peek());
                            operator.pop();
                        }
                        operator.push(imput.charAt(index));
                    }
                } else {
                    index++;
                    continue;
                }
                index++;
            }
            if (temp_num != 0)
                operand.push(temp_num);

            // 檢查是否還有運算子尚未運算
            while (!operator.empty()) {
                operand.push(count(operand, operator.peek()));
                operator.pop();
            }
            System.out.println("total=" + operand.peek());
            operand.pop();
        }
    }

    // 運算函式實作
    public static Integer count(Stack<Integer> s, Character c) {
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
                if (back == 0)
                    System.out.println("Division by zero is not allowed.");
                else
                    result = front / back;
                break;
        }
        return result;
    }
}
