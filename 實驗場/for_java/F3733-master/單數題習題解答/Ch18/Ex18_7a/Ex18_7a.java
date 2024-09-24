// Ex18_7a
import java.net.*;
import java.io.*;
import javax.swing.*;
import java.awt.event.*;
public class Ex18_7a extends JFrame implements ActionListener{
    static Ex18_7a frm=new Ex18_7a();
    static JButton btn=new JButton("連線");
    static JTextArea txa=new JTextArea("",6,22);
    static JPanel pne=new JPanel();
    static public void main(String args[]){
        frm.setSize(240,190);
        frm.setTitle("Server");
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
            try{
                ServerSocket svs=new ServerSocket(2525);
                txa.append("等候客戶端的請求中..."+"\n");
                Socket s=svs.accept();
                txa.append("客戶端已和本機連上線..."+"\n");
                txa.append("資料正在傳送中..."+"\n");
                OutputStream out=s.getOutputStream();
                String str="Honor shows the man.";
                out.write(str.getBytes());
                out.close();
                s.close();
                svs.close();
                txa.append("資料傳送完畢..."+"\n");
            }
            catch(IOException ie){
                System.out.println("發生了"+ie+"例外");
            }
            btn.setEnabled(false);
        }
    }
}