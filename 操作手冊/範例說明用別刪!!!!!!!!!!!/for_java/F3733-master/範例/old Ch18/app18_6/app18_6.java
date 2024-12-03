// app18_6, TextEvent���O���ϥνd��
import java.awt.*;
import java.awt.event.*;
public class app18_6 extends Frame implements TextListener
{
   static app18_6 frm=new app18_6(); 
   static TextArea txa1;
   static TextArea txa2;
   
   public static void main(String args[])
   {
      txa1=new TextArea("",6,10,TextArea.SCROLLBARS_NONE);
      txa2=new TextArea("",6,10,TextArea.SCROLLBARS_NONE);
      frm.setSize(200,150);
      frm.setTitle("Text Event");
      frm.setLayout(new FlowLayout(FlowLayout.CENTER));
      txa1.addTextListener(frm); // �Nfrm�]��txa1����ť��
      txa2.setEditable(false);      // �Ntxa2�]�w�����i�s��
      frm.add(txa1);      
      frm.add(txa2);
      frm.setVisible(true); 
   }
   // ��txa1����̪���r���ܮɡA����U�C���{���X
   public void textValueChanged(TextEvent e)  
   {
      txa2.setText(txa1.getText());
   }
}