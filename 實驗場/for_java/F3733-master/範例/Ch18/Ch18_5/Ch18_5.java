// Ch18_5, 使用URLConnection類別
import java.net.*;
import java.io.*;
public class Ch18_5{
    public static void main(String args[]){
        try{
            URL u1=new URL("https://www.hinet.net");
            URL u2=new URL("file:///C:\\MyJava\\Ch18\\Ch18_5\\poem.txt");
            URL u3=new URL("file:///C:\\MyJava\\Ch18\\Ch18_5\\pic0.png");

            URLConnection uc1=u1.openConnection();
            URLConnection uc2=u2.openConnection();
            URLConnection uc3=u3.openConnection();

            System.out.print("主網頁的大小為 " + uc1.getContentLength());
            System.out.println(",  類型為 " + uc1.getContentType());
            System.out.print("poem.txt的大小為 " + uc2.getContentLength());
            System.out.println(",  類型為 " + uc2.getContentType());
            System.out.print("pic0.jpg的大小為 " + uc3.getContentLength());
            System.out.println(",  類型為 " + uc3.getContentType());
        }
        catch(IOException e){
            System.out.println("發生了"+e+"例外");
        }
    }
}