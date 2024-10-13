// Ex18_7b
import java.net.*;
import java.io.*;
import javax.swing.*;
import java.awt.event.*;
public class Ex18_7b extends JFrame implements ActionListener{
    static Ex18_7b frm=new Ex18_7b();
    static JButton btn=new JButton("連線");
    static JTextArea txa=new JTextArea("",6,22);
    static JPanel pne=new JPanel();
    static public void main(String args[]){      
        frm.setSize(240,190);
        frm.setTitle("Client");
        btn.addActionListener(frm);
        txa.setEditable(false);
        pne.add(txa);
        pne.add(btn);
        frm.add(pne);
        frm.setVisible(true);
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    public void actionPerformed(ActionEvent e){
        txa.setText("");
        JButton mybtn=(JButton) e.getSource();
        if(mybtn==btn){
            byte buff[]=new byte[1024];
            try{
                txa.append("正在與伺服器建立連線..."+"\n");
                Socket s=new Socket("127.0.0.1",2525);
                txa.append("已經與伺服器取得連線..."+"\n");
                InputStream in=s.getInputStream();
                int n=in.read(buff);
                txa.append("從伺服端收到: ");
                txa.append(new String(buff,0,n));
                in.close();
                s.close();
            }
            catch(Exception ee){
                System.out.println("發生了"+ee+"例外");
            }
            btn.setEnabled(false);
        }
    }
}