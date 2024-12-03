// app19_8, ��ܤ�����������
import java.awt.*;  
import java.awt.event.*;  
public class app19_8 extends Frame implements ActionListener
{
   static app19_8 frm=new app19_8();
   static Dialog dlg=new Dialog(frm);  // �إ�Dialog����dlg
   static Button Close_btn=new Button("Close");    // Close ���s
   static Button Cancel_btn=new Button("Cancel");  // Cancel���s
   static WinLis wlis=new WinLis(); // �إ߶�ť�̪���wlis
   
   public static void main(String args[])
   {
      frm.setTitle("Dialog Demo");
      frm.setSize(200,150);
      dlg.setTitle("Are you sure?");   // �]�w��ܤ�������D
      dlg.setSize(140,100);            // �]�w��ܤ�����j�p
      dlg.setLayout(new FlowLayout(FlowLayout.CENTER,5,30));
      dlg.add(Close_btn);        // �NClose_btn�[�J��ܤ����
      dlg.add(Cancel_btn);       // �NCancel_btn�[�J��ܤ����
      Cancel_btn.addActionListener(frm); // �]�wCancel_btn����ť��
      Close_btn.addActionListener(frm);  // �]�wClose_btn����ť��
      frm.addWindowListener(wlis);      // �]�wfrm����ť��
      frm.setVisible(true); 
   }
   
   static class WinLis extends WindowAdapter  
   {
      public void windowClosing(WindowEvent e) // ���U���������s��
      {
         dlg.setLocation(80,30); // �]�w��ܤ������m
         dlg.show();                   // ��ܹ�ܤ��
      }
   }    
   
   public void actionPerformed(ActionEvent e) // ���U��ܤ���W�����s��
   {
      Button btn=(Button) e.getSource();   // ���o�Q���U�����s
      if(btn==Close_btn)         // �p�G�OClose���s�Q���U
      {
         dlg.dispose();          // ������ܤ��
         frm.dispose();          // ��������
      }
      else if (btn==Cancel_btn)     // �p�G�OCancel���s�Q���U
         dlg.hide();             // ���ù�ܤ��
   }
}