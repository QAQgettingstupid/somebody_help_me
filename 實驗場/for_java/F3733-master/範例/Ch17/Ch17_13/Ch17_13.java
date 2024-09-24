// Ch17_13, JTextArea類別的應用
import javax.swing.*;
public class Ch17_13{
    static JFrame frm=new JFrame("JTextArea class"); 
    static JTextArea txa=new JTextArea();
    
    public static void main(String args[]){        
        JScrollPane jsp=new JScrollPane(txa,JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        jsp.setBounds(55,15,140,80);    // 設定文字捲軸區的大小        
        frm.setLayout(null);			// 不使用版面配置
        frm.setSize(270,150);
        frm.add(jsp);
        frm.setVisible(true);
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}