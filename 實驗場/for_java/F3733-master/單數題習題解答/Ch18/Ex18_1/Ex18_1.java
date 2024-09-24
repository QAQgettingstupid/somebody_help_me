// Ex18_1
import java.net.*;
import javax.swing.*;
import java.awt.event.*;
public class Ex18_1 extends JFrame implements ActionListener{
    static Ex18_1 frm=new Ex18_1();
    static JButton btn1=new JButton("Host name");
    static JButton btn2=new JButton("Host address");
    static JLabel lab=new JLabel("InetAddress class");
    static JPanel pne=new JPanel();

    public static void main(String args[])   {
        btn1.addActionListener(frm);
        btn2.addActionListener(frm);        
        frm.setTitle("InetAddress class");        
        frm.setSize(300,120);        
        pne.add(btn1);
        pne.add(btn2);
        pne.add(lab);
        frm.add(pne);
        frm.setVisible(true);
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public void actionPerformed(ActionEvent e){
        try{
            JButton btn=(JButton)e.getSource();
            InetAddress adr=InetAddress.getLocalHost();
            if(btn==btn1)
                lab.setText(adr.getHostName());
            else if(btn== btn2)
                lab.setText(adr.getHostAddress());
        }
        catch(UnknownHostException ue){
            lab.setText("無法取得Ip位置");
        }
    }
}