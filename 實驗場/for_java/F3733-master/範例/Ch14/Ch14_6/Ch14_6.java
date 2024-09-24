// Ch14_6, 讀入與寫入二進位檔案
import java.io.*;
public class Ch14_6{
    public static void main(String[] args) throws IOException{
        FileInputStream fi=new FileInputStream("C:\\MyJava\\Ch14\\Ch14_6\\Lena.png");
        FileOutputStream fo=new FileOutputStream("C:\\MyJava\\Ch14\\Ch14_6\\MyLena.png"); 
           
        System.out.println("file size="+fi.available()); // 印出檔案大小
        byte data[]=new byte[fi.available()];  // 建立byte型態的陣列data

        fi.read(data); 		// 將圖檔讀入data陣列
        fo.write(data);		// 將data陣列裡的資料寫入新檔my_lena.png
        System.out.println("file copied and renamed");
        fi.close();
        fo.close();      
    }
}