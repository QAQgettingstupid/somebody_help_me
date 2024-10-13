// Ex17_15
import java.awt.event.*;
import javax.swing.*;
public class Ex17_15 extends JFrame implements KeyListener,ActionListener,ItemListener{
    static Ex17_15 frm=new Ex17_15();
    static JRadioButton rb1=new JRadioButton("奇數");
    static JRadioButton rb2=new JRadioButton("偶數");    
    static JTextField txf1=new JTextField(5);
    static JTextField txf2=new JTextField(5);
    static JPanel pne=new JPanel();
    static JButton btn=new JButton("Start");
    static JLabel lab1=new JLabel("From");
    static JLabel lab2=new JLabel("To");
    static JTextArea txa=new JTextArea();
    static int a,b;
    static String stra,strb;
    public static void main(String args[]){
        ButtonGroup bgroup=new ButtonGroup();
        bgroup.add(rb1);
        bgroup.add(rb2);
        JScrollPane jsp=new JScrollPane(txa,JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
        frm.setTitle("JFrame");
        frm.setSize(300,275);        
        txa.setEditable(false);   
       
        txf1.addKeyListener(frm);
        txf2.addKeyListener(frm);
        btn.addActionListener(frm); 
        rb1.addItemListener(frm);
        rb2.addItemListener(frm);
        rb1.setSelected(true);

        lab1.setBounds(20,40,35,20);
        txf1.setBounds(60,40,50,20);
        lab2.setBounds(120,40,20,20);
        txf2.setBounds(150,40,50,20);  
        rb1.setBounds(220,40,70,35);
        rb2.setBounds(220,80,70,35);
        btn.setBounds(110,70,70,20);
        jsp.setBounds(20,70,250,150);        

        txa.setLineWrap(true);
        txa.setWrapStyleWord(true);
        pne.add(rb1);
        pne.add(rb2);
        pne.add(lab1);
        pne.add(txf1);
        pne.add(lab2);
        pne.add(txf2);
        pne.add(btn);                    
        frm.add(jsp);
        frm.add(pne);    
        frm.setVisible(true); 
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);    
    } 
    public void actionPerformed(ActionEvent e){        
        txa.setText("");
        a=Integer.parseInt(stra);
        b=Integer.parseInt(strb);        
        if(rb1.isSelected()){
            for(int i=a;i<=b;i++)
                if(i%2==1)
                    txa.append(i+" ");
        }        
        else{
            for(int i=a;i<=b;i++)
                if(i%2==0)
                    txa.append(i+" ");
        } 
    }   
    public void keyReleased(KeyEvent e){      
        JTextField tx=(JTextField)e.getSource();
        if(tx==txf1)
            stra=tx.getText();
        else if(tx==txf2)
            strb=tx.getText();
    }   
    public void keyPressed(KeyEvent e){ }
    public void keyTyped(KeyEvent e){ }
    public void textValueChanged(TextEvent e){ }
    public void itemStateChanged(ItemEvent e){ }
}