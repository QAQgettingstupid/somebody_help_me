// app19_8, 對話方塊的實例應用
import java.awt.*;  
import java.awt.event.*;  
public class app19_8 extends Frame implements ActionListener
{
   static app19_8 frm=new app19_8();
   static Dialog dlg=new Dialog(frm);  // 建立Dialog物件dlg
   static Button Close_btn=new Button("Close");    // Close 按鈕
   static Button Cancel_btn=new Button("Cancel");  // Cancel按鈕
   static WinLis wlis=new WinLis(); // 建立傾聽者物件wlis
   
   public static void main(String args[])
   {
      frm.setTitle("Dialog Demo");
      frm.setSize(200,150);
      dlg.setTitle("Are you sure?");   // 設定對話方塊的標題
      dlg.setSize(140,100);            // 設定對話方塊的大小
      dlg.setLayout(new FlowLayout(FlowLayout.CENTER,5,30));
      dlg.add(Close_btn);        // 將Close_btn加入對話方塊中
      dlg.add(Cancel_btn);       // 將Cancel_btn加入對話方塊中
      Cancel_btn.addActionListener(frm); // 設定Cancel_btn的傾聽者
      Close_btn.addActionListener(frm);  // 設定Close_btn的傾聽者
      frm.addWindowListener(wlis);      // 設定frm的傾聽者
      frm.setVisible(true); 
   }
   
   static class WinLis extends WindowAdapter  
   {
      public void windowClosing(WindowEvent e) // 按下視窗關閉鈕時
      {
         dlg.setLocation(80,30); // 設定對話方塊的位置
         dlg.show();                   // 顯示對話方塊
      }
   }    
   
   public void actionPerformed(ActionEvent e) // 按下對話方塊上的按鈕時
   {
      Button btn=(Button) e.getSource();   // 取得被按下的按鈕
      if(btn==Close_btn)         // 如果是Close按鈕被按下
      {
         dlg.dispose();          // 關閉對話方塊
         frm.dispose();          // 關閉視窗
      }
      else if (btn==Cancel_btn)     // 如果是Cancel按鈕被按下
         dlg.hide();             // 隱藏對話方塊
   }
}