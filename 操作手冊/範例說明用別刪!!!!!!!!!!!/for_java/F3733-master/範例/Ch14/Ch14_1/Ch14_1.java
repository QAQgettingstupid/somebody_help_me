// Ch14_1, 使用FileReader類別讀取檔案
import java.io.*;         			// 載入java.io類別庫裡的所有類別
public class Ch14_1{	
    public static void main(String args[]) throws IOException{
        char data[]=new char[128];	// 建立可容納128個字元的陣列 
        FileReader fr=new FileReader("C:\\Users\\pc\\Desktop\\入門到入墳\\操作手冊\\範例說明用別刪!!!!!!!!!!!\\for_java\\F3733-master\\範例\\Ch14\\Ch14_1\\train.txt"); // 建立物件fr
        
        int num=fr.read(data);		// 將資料讀入字元陣列data內
        String str=new String(data,0,num);  	// 將字元陣列轉換成字串
        System.out.println("Characters read= "+num); 
        System.out.println(str);
      
      fr.close();   
   }
}
