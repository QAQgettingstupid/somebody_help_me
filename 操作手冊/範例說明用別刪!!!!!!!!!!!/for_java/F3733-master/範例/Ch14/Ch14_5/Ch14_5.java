// Ch14_5, 利用FileInputStream讀取檔案
import java.io.*;
public class Ch14_5{
    public static void main(String args[]) throws IOException   {
        FileInputStream fi=new FileInputStream("C:\\MyJava\\Ch14\\Ch14_5\\train.txt");
        System.out.println("file size="+fi.available());
        byte ba[]=new byte[fi.available()];	// 建立byte陣列
      
        fi.read(ba);  // 將讀取的內容寫到陣列ba裡
        System.out.println(new String(ba));	// 印出陣列ba的內容
        fi.close();
    }
}