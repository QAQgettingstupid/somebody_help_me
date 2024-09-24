// Ex17_13
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class Ex17_13 extends JFrame implements AdjustmentListener{
    static Ex17_13 frm=new Ex17_13();
    static JScrollBar hbar=new JScrollBar(JScrollBar.HORIZONTAL,5,1,1,501);
    static JScrollBar vbar=new JScrollBar(JScrollBar.VERTICAL,5,1,1,501);
    static JLabel lab=new JLabel("ScrollBar");   
   
    public static void main(String args[]){ 
        BorderLayout border=new BorderLayout();
        frm.setLayout(border);     
        frm.setTitle("JScrollBar");
        frm.setSize(250,150);       

        frm.getContentPane().add(vbar,BorderLayout.EAST);
        frm.getContentPane().add(hbar,BorderLayout.SOUTH); 
        frm.getContentPane().add(lab,BorderLayout.CENTER);
 
        vbar.addAdjustmentListener(frm);
        hbar.addAdjustmentListener(frm);
        frm.setVisible(true);
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);     
    } 
   
    public void adjustmentValueChanged(AdjustmentEvent e){      
        int x=hbar.getValue();      
        int y=vbar.getValue();
        lab.setText("ScrollBar at("+x+","+y+")");        
    }   
}