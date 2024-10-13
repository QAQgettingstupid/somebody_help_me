// Ex18_3
import java.net.*;
import java.io.*;
import java.awt.event.*;
import javax.swing.*;
public class Ex18_3 extends JFrame implements ActionListener{
    static Ex18_3 frm=new Ex18_3();
    static JTextArea txa=new JTextArea("",6,10);
    static JButton btn=new JButton("Show");
    static JPanel pne=new JPanel();

    public static void main(String args[]){        
        btn.addActionListener(frm);
        txa.setEditable(false);
        frm.setSize(250,160);
        frm.setTitle("URL");
        pne.add(txa);
        pne.add(btn);        
        frm.add(pne);
        frm.setVisible(true);
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    public void actionPerformed(ActionEvent e){
        String str;
        JButton mybtn=(JButton) e.getSource();
        if(mybtn==btn){
            txa.setText("");
            try{
                URL u=new URL("file:/C:\\MyJava\\Ex18_3\\poem.txt");

                Object obj=u.getContent();
                InputStreamReader isr=new InputStreamReader((InputStream)obj);
                BufferedReader br=new BufferedReader(isr);

                while((str=br.readLine())!=null)
                    txa.append(str+"\n");
                br.close();
            }
            catch(IOException ie){
                System.out.println("發生了"+e+"例外");
            }
        }
    }
}