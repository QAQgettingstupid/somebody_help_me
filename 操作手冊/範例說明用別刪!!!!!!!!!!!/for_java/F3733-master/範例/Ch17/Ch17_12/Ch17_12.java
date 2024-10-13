// Ch17_12, JTextField與JPasswordField的應用
import javax.swing.*;
public class Ch17_12{
    static JFrame frm=new JFrame("JTextField class"); 
    static JTextField txf1=new JTextField("JTextField Demo");
    static JTextField txf2=new JTextField("Editable");
    static JPasswordField txf3=new JPasswordField("password");
    
    public static void main(String args[]){        
        frm.setSize(270,180);
        frm.setLayout(null);       
        txf1.setBounds(70,30,120,20);
        txf2.setBounds(70,60,120,20);
        txf3.setBounds(70,90,120,20);
        txf1.setEditable(false);		// 設定txf1為不可編輯
        txf3.setEchoChar('*');			// 設定txf3的回應字元為'*'
        frm.add(txf1);
        frm.add(txf2); 
        frm.add(txf3); 
        System.out.println(txf1.getText()); 
        System.out.println(txf2.getText()); 
        System.out.println(txf3.getPassword());
        frm.setVisible(true); 
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}