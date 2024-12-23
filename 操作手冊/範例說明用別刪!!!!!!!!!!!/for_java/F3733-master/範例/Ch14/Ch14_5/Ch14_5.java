
// Ch14_5, 利用FileInputStream讀取檔案
import java.io.*;

public class Ch14_5 {
    public static void main(String args[]) throws IOException {
        FileInputStream fi = new FileInputStream(
                "C:\\Users\\pc\\Desktop\\入門到入墳\\操作手冊\\範例說明用別刪!!!!!!!!!!!\\for_java\\F3733-master\\範例\\Ch14\\Ch14_5\\train.txt");
        System.out.println("file size=" + fi.available());
        int readed = 0;
        byte ba[] = new byte[256]; // 建立byte陣列

        while (readed < fi.available()) {
            readed += fi.read(ba);
            System.out.println(new String(ba)); // 印出陣列ba的內容
            System.out.println("fi.available() =" + fi.available()); // 印出陣列ba的內容
        }
        fi.close();
    }
}