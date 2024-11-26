
// Ch17_9, JButton與JLabel的綜合應用
import javax.swing.*;
import java.awt.event.*;

public class Ch17_9 {
    static JFrame frm = new JFrame("JButton & JLabel");
    static JPanel pne = new JPanel();

    static ImageIcon pic[] = new ImageIcon[4]; // 建立ImageIcon陣列
    static ImageIcon left = new ImageIcon(
            "C:\\Users\\藤井夕夜\\Desktop\\somebody_help_me\\操作手冊\\範例說明用別刪!!!!!!!!!!!\\for_java\\F3733-master\\範例\\Ch17\\Ch17_9\\left.png");
    static ImageIcon right = new ImageIcon(
            "C:\\Users\\藤井夕夜\\Desktop\\somebody_help_me\\操作手冊\\範例說明用別刪!!!!!!!!!!!\\for_java\\F3733-master\\範例\\Ch17\\Ch17_9\\right.png");

    static JButton btn1 = new JButton(" 前一張 ", left);
    static JButton btn2 = new JButton(" 後一張 ", right);
    static JLabel lab = new JLabel();
    static int index = 0; // index變數，用來記錄哪一張影像正被顯示

    public static void main(String args[]) {
        pic[0] = new ImageIcon(
                "C:\\Users\\藤井夕夜\\Desktop\\somebody_help_me\\操作手冊\\範例說明用別刪!!!!!!!!!!!\\for_java\\F3733-master\\範例\\Ch17\\Ch17_9\\pic0.png");// 載入影像
        pic[1] = new ImageIcon(
                "C:\\Users\\藤井夕夜\\Desktop\\somebody_help_me\\操作手冊\\範例說明用別刪!!!!!!!!!!!\\for_java\\F3733-master\\範例\\Ch17\\Ch17_9\\pic1.png");
        pic[2] = new ImageIcon(
                "C:\\Users\\藤井夕夜\\Desktop\\somebody_help_me\\操作手冊\\範例說明用別刪!!!!!!!!!!!\\for_java\\F3733-master\\範例\\Ch17\\Ch17_9\\pic2.png");
        pic[3] = new ImageIcon(
                "C:\\Users\\藤井夕夜\\Desktop\\somebody_help_me\\操作手冊\\範例說明用別刪!!!!!!!!!!!\\for_java\\F3733-master\\範例\\Ch17\\Ch17_9\\pic3.png");
        // 設定文字水平位置
        btn2.setHorizontalTextPosition(JButton.LEFT);
        pne.add(btn1);
        pne.add(btn2);
        pne.add(lab);
        frm.add(pne);

        lab.setIcon(pic[0]);
        lab.setText("pic0.png");
        // 設定文字水平位置
        lab.setHorizontalTextPosition(JLabel.CENTER);
        // 設定文字垂直位置
        lab.setVerticalTextPosition(JLabel.BOTTOM);

        btn1.addActionListener(new ActLis());
        btn2.addActionListener(new ActLis());

        frm.setSize(400, 300);
        frm.setVisible(true);
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    static class ActLis implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            JButton btn = (JButton) e.getSource(); // 取得被按下的按鈕 (JButton)->強制型別轉換
            int num = pic.length;

            if (btn == btn1 && index > 0) // 若btn1被按下，且index>0
                index--;
            if (btn == btn2 && index < num - 1)// 若btn2被按下，且index<num-1
                index++;
            lab.setText("pic" + index + ".png"); // 設定標題名稱
            lab.setIcon(pic[index]);
        }
    }
}