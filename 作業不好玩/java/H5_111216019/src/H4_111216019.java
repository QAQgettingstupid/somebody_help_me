import java.util.Scanner;
import java.util.HashMap;
import java.util.Stack;
import java.util.Map;

public class H4_111216019 {
    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        Map<Character, Integer> priority = new HashMap<>();
        priority.put('-', 1);
        priority.put('+', 1);
        priority.put('/', 2);
        priority.put('*', 2);
        priority.put('(', 100);

        while (scn.hasNext()) {
            String imput = scn.nextLine();
            Stack<Character> operator = new Stack<>();
            Stack<Integer> operand = new Stack<>();
            int index = 0, temp_num = 0;

            // 逐個讀取輸入字元
            while (index < imput.length()) {
                if (imput.charAt(index) <= '9' && imput.charAt(index) >= '0') {
                    temp_num *= 10;
                    temp_num += imput.charAt(index) - '0';
                } else if (imput.charAt(index) == '(')
                    operator.push(imput.charAt(index));

                // 都還沒實作,負數辨認也還沒搞
                else if (imput.charAt(index) == '+' || imput.charAt(index) == '-' || imput.charAt(index) == '*'
                        || imput.charAt(index) == '/' || imput.charAt(index) == ')') {
                    if (imput.charAt(index) == ')') {
                        // 還沒打
                    }
                    operand.push(temp_num);
                    temp_num = 0;
                }
                index++;
            }
            if (!operand.empty())
                System.out.println(operand.peek());
        }
    }
}
