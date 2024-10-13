// Ex17_5
import javax.swing.*;
public class Ex17_5{
    static JFrame frm=new JFrame("Frame 5");
    static JPanel pne=new JPanel();
    static JLabel lab=new JLabel();
    static ImageIcon pic=new ImageIcon("C:\\MyJava\\Ex17_5\\agave.png");
    static ImageIcon img=new ImageIcon("C:\\MyJava\\Ex17_5\\ok.png");
    static JButton btn1=new JButton(" OK",img);
       
    public static void main(String args[]){ 
        frm.setSize(250,260);
        lab.setIcon(pic);
        pne.add(lab);        
        pne.add(btn1);
        frm.add(pne);
        frm.setVisible(true);
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}

/* output--------

---------------*/