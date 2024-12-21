import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.util.HashMap;
import java.util.Map;
import java.util.Stack;
import java.awt.event.ActionEvent;

//作者:蔡芳宇
//學號:111216019
//自評:20%+30%+25%+25% 沒有太多的例外處裡請放過我QAQ ,很抱歉介面這麼陽春

public class H7_111216019 extends JFrame implements ActionListener {

    static H7_111216019 frm = new H7_111216019("小算盤");
    static JPanel pne = new JPanel();
    static JTextField text = new JTextField("0");
    static JButton btns[] = new JButton[16];
    static JButton btn_ac = new JButton("Clear all");
    static String btname[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ".", "+", "-", "*", "/", "=" };
    static String input = "";

    public H7_111216019(String title) {
        super(title);
    }

    public static void main(String[] args) {

        Font font = new Font("Arial", Font.PLAIN, 20);

        // 按鍵初始化
        for (int i = 0; i < 16; i++) {
            int hight = (i % 4) * 30 + 50;
            int width = (i / 4) * 90;
            btns[i] = new JButton(btname[i]);
            btns[i].setBounds(width, hight, 90, 30);
            btns[i].addActionListener(frm);
            btns[i].setFont(font);
            pne.add(btns[i]);
        }

        // 輸入框
        text.setBounds(0, 0, 350, 50);
        text.setHorizontalAlignment(SwingConstants.RIGHT);
        text.setFont(font);

        //clear all初始化
        btn_ac.setBounds(0, 170, 360, 30);
        btn_ac.addActionListener(frm);
        btn_ac.setFont(font);

        pne.add(text);
        pne.add(btn_ac);

        // frm設定
        frm.add(pne);
        frm.setSize(360, 237);
        pne.setLayout(null);
        frm.setResizable(false);
        frm.setVisible(true);
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public void actionPerformed(ActionEvent e) {

        Object btn = e.getSource();

        if (((JButton) btn).getText() == "=")
            calculate();
        else if (((JButton) btn).getText() == "Clear all") {
            input = "0";
            text.setText(input);
        } else {
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
        Stack<Double> operand = new Stack<>();
        Double temp_num;
        int index = 0, numfront = 0;
        boolean negative = false, changed = false;

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
                    while (operator.peek() != '(') {
                        operand.push(count(operand, operator.peek()));
                        operator.pop();
                    }
                    operator.pop();
                }

                else {

                    // 輸入優先權小於等於stack top,先pop進行運算
                    while (!operator.empty()
                            && priority.get(operator.peek()) >= priority.get(input.charAt(index))) {

                        operand.push(count(operand, operator.peek()));
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
        while (!operator.empty()) {
            operand.push(count(operand, operator.peek()));
            operator.pop();
        }
        input = Double.toString(operand.peek());
        text.setText(Double.toString(operand.peek()));
    }

    public static Double count(Stack<Double> s, Character c) {
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
