// Ex18_9b
import java.net.*;
import java.io.*;
import javax.swing.*;
import java.awt.event.*;
public class Ex18_9b extends JFrame implements ActionListener,TextListener{
    static Ex18_9b frm=new Ex18_9b();
    static JButton btn=new JButton("連線+傳送");
    static JTextField txf=new JTextField("Never too old to learn.",20);
    static JTextArea txa=new JTextArea("",6,22);
    static JPanel pne=new JPanel();
    static public void main(String args[]){      
        frm.setSize(240,220);
        frm.setTitle("客戶端");
        btn.addActionListener(frm);
        txa.setEditable(false);
        pne.add(txf);
        pne.add(txa);
        pne.add(btn);
        frm.add(pne);
        frm.setVisible(true);
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    public void actionPerformed(ActionEvent e){
        txa.setText("");
        JButton mybtn=(JButton) e.getSource();
        byte buff[]=new byte[1024];
        if(mybtn==btn){            
            try{
                txa.append("正在與伺服器建立連線..."+"\n");
                Socket s=new Socket("127.0.0.1",2525);
                txa.append("已經與伺服器取得連線..."+"\n");
                OutputStream out=s.getOutputStream();
                String send_str=txf.getText();
                txa.append("傳送"+send_str+"到伺服端..."+"\n");
                out.write(send_str.getBytes());
                txf.setEditable(false);
                InputStream in=s.getInputStream();
                int n=in.read(buff);
                txa.append("從伺服端收到: ");
                String str=new String(buff,0,n);
                txa.append(str+"\n");    
                in.close();
                s.close();
            }
            catch(IOException ee){
                System.out.println("發生了"+ee+"例外");
            }
            btn.setEnabled(false);            
        }
    }
    public void textValueChanged(TextEvent e){}
}