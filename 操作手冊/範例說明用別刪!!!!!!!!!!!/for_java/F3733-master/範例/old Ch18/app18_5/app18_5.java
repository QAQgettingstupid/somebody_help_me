
// app18_5, ItemEvent���O���ϥνd��
import java.awt.*;
import java.awt.event.*;

import javax.swing.JFrame;

public class app18_5 extends Frame implements ItemListener {
   static app18_5 frm = new app18_5();
   static Checkbox ckb1 = new Checkbox("Epson 5900L");
   static Checkbox ckb2 = new Checkbox("HP LaserJet 4p");
   static Label lab = new Label(" Select a printer ");

   public static void main(String args[]) {
      CheckboxGroup grp = new CheckboxGroup();
      frm.setSize(200, 150);
      frm.setTitle("Item Event");
      frm.setLayout(new FlowLayout(FlowLayout.LEFT));
      ckb1.setCheckboxGroup(grp); // �Nckb1�]�����
      ckb2.setCheckboxGroup(grp); // �Nckb2�]�����
      lab.setBackground(Color.orange);
      ckb1.addItemListener(frm); // ��frm����ckb1����ť��
      ckb2.addItemListener(frm); // ��frm����ckb2����ť��
      frm.add(lab);
      frm.add(ckb1);
      frm.add(ckb2);
      frm.setVisible(true);
   }

   // ItemEvent�ƥ�o�ͮɪ��B�z�ʧ@
   public void itemStateChanged(ItemEvent e) {
      if (ckb1.getState() == true) // �p�G�Ockb1�Q���
         lab.setText(" Epson 5900L");
      else if (ckb2.getState() == true) // �p�G�Ockb2�Q���
         lab.setText(" HP LaserJet 4p");
   }
}