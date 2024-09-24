// Ex17_11
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class Ex17_11 extends JFrame implements ActionListener{
    static Ex17_11 frm=new Ex17_11();
    static JPanel pne=new JPanel();
    static JLabel lab=new JLabel();
    static ImageIcon icn1=new ImageIcon("C:\\MyJava\\Ex17_11\\red.gif");
    static ImageIcon icn2=new ImageIcon("C:\\MyJava\\Ex17_11\\green.gif");
    static JButton btn1=new JButton("Red");
    static JButton btn2=new JButton("Green");

    public static void main(String args[]){        
        frm.setTitle("JButton & JLabel");
        pne.setBackground(Color.orange);
        pne.add(btn1);
        pne.add(btn2);
        pne.add(lab);
        btn1.addActionListener(frm);
        btn2.addActionListener(frm);
        btn1.setIcon(icn1);
        btn2.setIcon(icn2);
        lab.setFont(new Font("Comic Sans MS",Font.PLAIN,18));
        lab.setForeground(Color.red);
        lab.setText("Make hay while the sun shines.");
        frm.add(pne);
        frm.setSize(300,130);
        frm.setVisible(true);
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    public void actionPerformed(ActionEvent e){
        JButton btn=(JButton) e.getSource();
        if(btn==btn1)
            lab.setForeground(Color.red);
        else if(btn==btn2)
            lab.setForeground(Color.green);
    }
}
