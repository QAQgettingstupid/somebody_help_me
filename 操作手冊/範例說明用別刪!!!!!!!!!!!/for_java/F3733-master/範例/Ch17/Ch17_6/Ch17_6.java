// Ch17_6, 簡單的事件處理範例(未加入事件處理)
import java.awt.*;
import javax.swing.*;
public class Ch17_6 extends JFrame{ // 設定Ch17_6類別繼承自JFrame類別
    static Ch17_6 frm=new Ch17_6();  // 建立Ch17_6類別的物件frm
    static JButton btn=new JButton("Click Me");
   
    public static void main(String args[]){          
        frm.setLayout(new FlowLayout());
        frm.setTitle("Action Event");
        frm.setSize(280,150);
        frm.add(btn);
        frm.setVisible(true);
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
