// Ex14_7
import java.io.*;
public class Ex14_7{
    public static void main(String args[]) throws IOException{
        FileWriter fw=new FileWriter("C:\\MyJava\\Ex14_7\\hello.txt",true);
        FileReader fr=new FileReader("C:\\Myjava\\Ex14_7\\hello.txt");

        int num;
        char data[]=new char[128];  // 將字串寫入檔案
        String str="\r\nWelcome!";
        fw.write(str);
        fw.close();

        num=fr.read(data);
        str=new String(data,0,num); // 讀檔
        System.out.println(str);
        fr.close();
    }
}

/* output------
Hello Java!
Welcome!
-------------*/