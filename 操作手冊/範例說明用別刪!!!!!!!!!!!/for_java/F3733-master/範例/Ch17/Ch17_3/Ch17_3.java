
// Ch17_3, JButton與JLabel的綜合應用
import javax.swing.*;

public class Ch17_3 {
   static JFrame frm = new JFrame("JButton & JLabel");
   static JPanel pne = new JPanel();

   static ImageIcon pic;
   static ImageIcon left = new ImageIcon(
         "C:\\Users\\藤井夕夜\\Desktop\\somebody_help_me\\操作手冊\\範例說明用別刪!!!!!!!!!!!\\for_java\\F3733-master\\範例\\Ch17\\Ch17_3\\left.png");
   static ImageIcon right = new ImageIcon(
         "C:\\Users\\藤井夕夜\\Desktop\\somebody_help_me\\操作手冊\\範例說明用別刪!!!!!!!!!!!\\for_java\\F3733-master\\範例\\Ch17\\Ch17_3\\right.png");

   static JButton btn1 = new JButton(" 前一張 ", left);
   static JButton btn2 = new JButton(" 後一張 ", right);
   static JLabel lab = new JLabel();

   public static void main(String args[]) {
      // 載入圖片
      pic = new ImageIcon(
            "C:\\Users\\藤井夕夜\\Desktop\\somebody_help_me\\操作手冊\\範例說明用別刪!!!!!!!!!!!\\for_java\\F3733-master\\範例\\Ch17\\Ch17_3\\pic0.png");
      // 設定文字水平位置
      btn2.setHorizontalTextPosition(JButton.LEFT);
      pne.add(btn1);
      pne.add(btn2);
      pne.add(lab);
      frm.add(pne);
      lab.setIcon(pic);
      lab.setText("pic0.png");
      // 設定文字水平位置
      lab.setHorizontalTextPosition(JLabel.CENTER);
      // 設定文字垂直位置
      lab.setVerticalTextPosition(JLabel.BOTTOM);
      frm.setSize(400, 300);
      frm.setVisible(true);
      frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
   }
}