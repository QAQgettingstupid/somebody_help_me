
// Ch14_2, 使用FileWriter類別將資料寫入檔案內
import java.io.*;

public class Ch14_2 {
   public static void main(String args[]) throws IOException {
      FileWriter fw = new FileWriter(
            "C:\\Users\\藤井夕夜\\Desktop\\somebody_help_me\\操作手冊\\範例說明用別刪!!!!!!!!!!!\\for_java\\F3733-master\\範例\\Ch14\\Ch14_2\\proverb.txt",
            true);
      char data[] = { 'T', 'i', 'm', 'e', ' ', 'f', 'l', 'i', 'e', 's', '!', '\r', '\n' };
      String str = "End of file\n";
      fw.write(data); // 將字元陣列寫到檔案裡
      fw.write(str); // 將字串寫到檔案裡
      fw.close();
   }
}
