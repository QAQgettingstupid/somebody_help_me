// Ch17_5, FlowLayout類別的使用
import java.awt.*;
import javax.swing.*;
public class Ch17_5{
    static JFrame frm=new JFrame("Flow Layout"); 
    public static void main(String args[]){        
        FlowLayout flow=new FlowLayout(FlowLayout.CENTER,5,10);
        frm.setLayout(flow);    				// 設定版面配置為流動式
        frm.setSize(280,180);         
        frm.add(new JButton("East"));
        frm.add(new JButton("West"));
        frm.add(new JButton("South"));
        frm.add(new JButton("North"));
        frm.add(new JButton("Center"));
        frm.setVisible(true);
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);      
    }
}