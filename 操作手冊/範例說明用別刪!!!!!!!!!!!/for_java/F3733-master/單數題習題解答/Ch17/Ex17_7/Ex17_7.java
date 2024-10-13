// Ex17_7
import java.awt.*;
import javax.swing.*;
public class Ex17_7{    
    static JFrame frm=new JFrame("Frame 7");  
    static JLabel lab=new JLabel("Honesty is the best policy.");
    static JPanel pne=new JPanel();
       
    public static void main(String args[]){           
        frm.setLayout(new FlowLayout());
        frm.setSize(230,120);
        pne.add(lab);
        pne.setBackground(Color.ORANGE);
        frm.add(pne);
        frm.add(new JButton("Ok"));
        frm.add(new JButton("Exit")); 
        frm.setVisible(true);
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}

/* output--------

---------------*/