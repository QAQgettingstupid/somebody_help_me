// Ex17_9
import javax.swing.*;
import java.awt.event.*;
public class Ex17_9{   
    static JFrame frm=new JFrame("JButton & JLabel");
    static JPanel pne=new JPanel();

    static ImageIcon pic[]=new ImageIcon[4];
    static ImageIcon left=new ImageIcon("C:\\Myjava\\Ex17_9\\left.png");
    static ImageIcon right=new ImageIcon("C:\\Myjava\\Ex17_9\\right.png");

    static JButton btn1=new JButton(" 前一張 ",left);
    static JButton btn2=new JButton(" 後一張 ",right);
    static JLabel lab=new JLabel();
    static int index=0;   
    public static void main(String args[]){  
        pic[0]=new ImageIcon("C:\\Myjava\\Ex17_9\\pic0.png");
        pic[1]=new ImageIcon("C:\\Myjava\\Ex17_9\\pic1.png");
        pic[2]=new ImageIcon("C:\\Myjava\\Ex17_9\\pic2.png");
        pic[3]=new ImageIcon("C:\\Myjava\\Ex17_9\\pic3.png");
   
        btn2.setHorizontalTextPosition(JButton.LEFT);
        pne.add(btn1);
        pne.add(btn2);
        pne.add(lab);
        frm.add(pne);

        lab.setIcon(pic[0]);
        lab.setText("pic0.png");
        lab.setHorizontalTextPosition(JLabel.CENTER);
        lab.setVerticalTextPosition(JLabel.BOTTOM);
         
        btn1.addActionListener(new ActLis());
        btn2.addActionListener(new ActLis());
        
        frm.setSize(400,300);
        frm.setVisible(true);
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    static class ActLis implements ActionListener{
        public void actionPerformed(ActionEvent e){
            JButton btn=(JButton) e.getSource();
            int num=pic.length;
      
            if(btn==btn1 && index>=0){
                if(index==0)
                    index=pic.length-1;
                else
                    index--;
            }
            if(btn==btn2 && index<=num-1){
                if(index==pic.length-1)
                    index=0;
                else
                    index++;
            }            
        lab.setText("pic"+ index%num +".png");
        lab.setIcon(pic[index%num]);
        }
    }
}

/* output--------

---------------*/