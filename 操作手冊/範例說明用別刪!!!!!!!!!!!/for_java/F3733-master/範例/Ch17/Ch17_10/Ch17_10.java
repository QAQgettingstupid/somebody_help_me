// Ch17_10, 核取方塊與選項方塊的應用
import javax.swing.*;
public class Ch17_10{
    static JFrame frm=new JFrame("Checkbox class");
    static JPanel pne=new JPanel();
    static JRadioButton rb1=new JRadioButton("數位攝影機");
    static JRadioButton rb2=new JRadioButton("數位相機");

    static JCheckBox ckb1=new JCheckBox("Sony",true);
    static JCheckBox ckb2=new JCheckBox("Nikon",true);
    static JCheckBox ckb3=new JCheckBox("Others");

    public static void main(String args[]){        
        rb1.setBounds(30,20,90,20); 
        rb2.setBounds(140,20,78,20);
        ckb1.setBounds(50,60,140,20);    
        ckb2.setBounds(50,80,140,20);
        ckb3.setBounds(50,100,140,20);

        ButtonGroup bgroup=new ButtonGroup(); 	// 建立ButtonGroup物件
        bgroup.add(rb1);     				    // 將rb1設定為單選
        bgroup.add(rb2);     				    // 將rb2設定為單選
        rb1.setSelected(true);  				// 設定rb1被選擇

        pne.add(rb1);
        pne.add(rb2);
        pne.add(ckb1);   
        pne.add(ckb2);
        pne.add(ckb3);
        pne.setLayout(null);   //setBounds 不會與 layout 同時用, 所以關閉 Layout 功能
        frm.add(pne);
        frm.setSize(270,180);
        frm.setVisible(true);
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}