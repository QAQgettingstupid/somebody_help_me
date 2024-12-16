import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.util.HashMap;
import java.util.Map;
import java.util.Stack;
import java.awt.event.ActionEvent;

public class H7_111216019 extends JFrame implements ActionListener {

    static H7_111216019 frm = new H7_111216019("小算盤");
    static JPanel pne = new JPanel();
    static JTextField text = new JTextField("0");
    static JButton btns[] = new JButton[16];
    static String btname[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ".", "+", "-", "*", "/", "=" };
    static String input = "";

    public H7_111216019(String title) {
        super(title);
    }

    public static void main(String[] args) {

        // 按鍵初始化
        for (int i = 0; i < 16; i++) {
            int hight = (i % 4) * 30 + 50;
            int width = (i / 4) * 90;
            btns[i] = new JButton(btname[i]);
            btns[i].setBounds(width, hight, 90, 30);
            btns[i].addActionListener(frm);
            pne.add(btns[i]);
        }
        // 輸入框
        text.setBounds(0, 0, 350, 50);
        text.setHorizontalAlignment(SwingConstants.RIGHT);
        pne.add(text);

        // frm設定
        frm.add(pne);
        frm.setSize(360, 500);
        pne.setLayout(null);
        frm.setResizable(false);
        frm.setVisible(true);
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public void actionPerformed(ActionEvent e) {

        Object btn = e.getSource();

        if (((JButton) btn).getText() == "=")
            calculate();
        else {
            input += ((JButton) btn).getText();
            text.setText(input);
        }
    }

    public static void calculate() {

        // 計算功能本體
        Map<Character, Integer> priority = new HashMap<>();
        priority.put('(', 0);
        priority.put('-', 1);
        priority.put('+', 1);
        priority.put('/', 2);
        priority.put('*', 2);

        Stack<Character> operator = new Stack<>();
        Stack<Integer> operand = new Stack<>();
        int index = 0, temp_num = 0;
        boolean negative = false, devide_0 = false, changed = false;

        // 逐個讀取輸入字元
        while (index < input.length()) {
            if (input.charAt(index) <= '9' && input.charAt(index) >= '0') {
                temp_num *= 10;
                temp_num += input.charAt(index) - '0';
                changed = true;
            } else if (input.charAt(index) == '+' || input.charAt(index) == '-' || input.charAt(index) == '*'
                    || input.charAt(index) == '/' || input.charAt(index) == '(' || input.charAt(index) == ')') {

                // 放入數字
                if (changed) {
                    if (negative) {
                        operand.push(temp_num * (-1));
                        negative = false;
                    } else
                        operand.push(temp_num);
                    temp_num = 0;
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
        if (changed)
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
            input=Integer.toString(operand.peek());
            operand.pop();
        }
        text.setText(input);
    }

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
