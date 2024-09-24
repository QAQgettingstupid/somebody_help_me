// Ex14_5
import java.io.*;
public class Ex14_5{
    public static void main(String args[]) throws IOException{
        char data[]=new char[128];
        FileReader fr=new FileReader("C:\\Myjava\\Ex14_5\\donkey.txt");
        fr.skip(9);
        int num=fr.read(data);
        String str=new String(data,0,num);
        System.out.println("Characters read= "+num);
        System.out.println(str);
        fr.close();
    }
}

/* output-------------------
Characters read= 21
我從來也不騎
有一天我心血來潮騎著去趕集
-------------------------*/