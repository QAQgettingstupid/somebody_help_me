// Ch17_8, 定義內部類別當成傾聽者
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class Ch17_8{   		// 主類別，注意此類別不需繼承JFrame類別
    static JFrame frm=new JFrame("Action Event"); 
    static JButton btn=new JButton("Click Me");
    static JPanel pne=new JPanel();
 
    public static void main(String args[]){        
        btn.addActionListener(new ActLis());
        frm.setSize(280,150);        
        pne.add(btn);        
        frm.add(pne);
        frm.setVisible(true);
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
    }
    // 定義內部類別ActLis，並實作ActionListener介面
    static class ActLis implements ActionListener{
        public void actionPerformed(ActionEvent e){   // 事件發生的處理動作           
            pne.setBackground(Color.YELLOW);
        }
    }   
}