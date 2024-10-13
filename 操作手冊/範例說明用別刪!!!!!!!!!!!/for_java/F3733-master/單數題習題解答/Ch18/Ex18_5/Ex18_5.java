// Ex18_5
import java.net.*;
import java.io.*;
import javax.swing.*;
import java.awt.event.*;
public class Ex18_5 extends JFrame implements ActionListener,TextListener{
    static Ex18_5 frm=new Ex18_5();
    static JTextField txf=new JTextField("https://hinet.net",20);
    static JTextArea txa=new JTextArea("",4,20);
    static JButton btn=new JButton("open connection");
    static JPanel pne=new JPanel();

    public static void main(String args[]){
        frm.setTitle("URL info");
        txf.addActionListener(frm);        
        frm.setSize(260,180);
        txa.setEditable(false);
        btn.addActionListener(frm);
        pne.add(txf);   
        pne.add(txa);
        pne.add(btn);
        frm.add(pne);
        frm.setVisible(true);
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    public void actionPerformed(ActionEvent e){      
        JButton mybtn=(JButton)e.getSource();
        try{
            txa.setText("");
            URL u1=new URL(txf.getText());            
            URLConnection uc1=(HttpURLConnection)u1.openConnection();
            if(mybtn==btn){
                txa.append("主網頁大小為"+uc1.getContentLength());
                txa.append("\n類型為"+uc1.getContentType()+"\n");
            }
        }
        catch(IOException ie){
            System.out.println("發生了"+ie+"例外");
        }
    }
    public void textValueChanged(TextEvent e){}
}
