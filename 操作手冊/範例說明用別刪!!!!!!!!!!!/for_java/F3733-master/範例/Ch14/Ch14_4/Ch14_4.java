// Ch14_4, 將資料寫到緩衝區內
import java.io.*;
public class Ch14_4{
    public static void main(String[] args) throws IOException{
        FileWriter fw=new FileWriter("C:\\Users\\藤井夕夜\\Desktop\\somebody_help_me\\操作手冊\\範例說明用別刪!!!!!!!!!!!\\for_java\\F3733-master\\範例\\Ch14\\Ch14_4\\random.txt"); 
        BufferedWriter bfw=new BufferedWriter(fw);
           
        for(int i=1;i<=5;i++){
            bfw.write(Double.toString(Math.random()));  // 寫入亂數到緩衝區
            bfw.newLine();	// 寫入換行符號
        }
        bfw.close();		// 將緩衝區內的資料寫到檔案裡
        fw.close();		// 關閉檔案
    }
}
