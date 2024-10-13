// Ch17_1, Swing的JFrame練習
import javax.swing.*;      	// 載入javax.swing類別庫裡的所有類別
public class Ch17_1{
    public static void main(String args[]){	
        JFrame frm=new JFrame("JFrame 視窗");        
        frm.setSize(260,150);   // 設定視窗大小
	    frm.setVisible(true);
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}