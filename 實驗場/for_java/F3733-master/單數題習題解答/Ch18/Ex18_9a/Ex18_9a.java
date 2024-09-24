// Ex18_9a
import java.net.*;
import java.io.*;
import javax.swing.*;
import java.awt.event.*;
public class Ex18_9a extends JFrame implements ActionListener{
    static Ex18_9a frm=new Ex18_9a();
    static JButton btn=new JButton("連線");
    static JTextArea txa=new JTextArea("",6,22);
    static JPanel pne=new JPanel();
    static public void main(String args[]){
        frm.setSize(240,220);
        frm.setTitle("伺服端");
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
        byte buff[]=new byte[1024];
        if(mybtn==btn){
            try{
                ServerSocket svs=new ServerSocket(2525);
                txa.append("等候客戶端的請求中..."+"\n");
                Socket s=svs.accept();
                txa.append("客戶端已和本機連上線..."+"\n");
                InputStream in=s.getInputStream();
                int n=in.read(buff);

                txa.append("從客戶端收到: ");
                String rec_str=new String(buff,0,n);
                txa.append(rec_str+"\n");
                txa.append("傳回"+rec_str+"到客戶端"+"\n");
                OutputStream out=s.getOutputStream();
                out.write(rec_str.getBytes());
                in.close();
                out.close();
                s.close(); 
                svs.close();  
            }
            catch(IOException ie){
                System.out.println("發生了"+ie+"例外");
            }
            btn.setEnabled(false);
        }
    }
}
