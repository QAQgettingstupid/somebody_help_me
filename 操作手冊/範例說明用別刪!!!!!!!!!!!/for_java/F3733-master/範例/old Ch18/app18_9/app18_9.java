
// app18_9, �HMouseListener�����B�zMouseEvent�ƥ�
import java.awt.*;
import java.awt.event.*;

public class app18_9 extends Frame implements MouseListener {
   static app18_9 frm = new app18_9();
   static Button btn = new Button(" Click Me!! ");
   static TextArea txa = new TextArea("", 2, 5, TextArea.SCROLLBARS_NONE);

   public static void main(String args[]) {
      BorderLayout br = new BorderLayout(2, 5);
      frm.setSize(200, 150);
      frm.setTitle("Mouse Event");
      frm.setLayout(br);
      btn.addMouseListener(frm); // �]�wfrm��btn����ť��
      txa.setEditable(false);
      frm.add(btn, br.WEST);
      frm.add(txa, br.CENTER);
      frm.setVisible(true);
   }

   public void mouseEntered(MouseEvent e) // �ƹ������жi�Jbtn�W��
   {
      txa.setText("Mouse entered\n");
      frm.setBackground(Color.MAGENTA);
   }

   public void mouseClicked(MouseEvent e) // ���U�é�}�ƹ����s
   {
      txa.append("Mouse clicked\n");
   }

   public void mouseExited(MouseEvent e) // �ƹ������в��}btn�W��
   {
      txa.append("Mouse exited\n");
      frm.setBackground(Color.WHITE);
   }

   public void mousePressed(MouseEvent e) // ���U�ƹ����s
   {
      txa.append("Mouse pressed\n");
      txa.setBackground(Color.ORANGE);
   }

   public void mouseReleased(MouseEvent e) // ��}�ƹ����s
   {
      txa.append("Mouse released\n");
      txa.setBackground(Color.WHITE);
   }
}