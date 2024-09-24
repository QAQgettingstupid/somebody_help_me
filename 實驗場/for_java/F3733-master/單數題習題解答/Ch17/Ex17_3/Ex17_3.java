// Ex17_3
import javax.swing.*;
public class Ex17_3{
    static JFrame frm=new JFrame("Frame 3");
    static JButton btn=new JButton("Push Me!!");
    static JPanel pne=new JPanel();

    public static void main(String args[]){        
        frm.setSize(250,120);        
        pne.add(btn);
        frm.add(pne);
        frm.setVisible(true);
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}

/* output--------

---------------*/