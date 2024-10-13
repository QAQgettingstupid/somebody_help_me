// Ex14_1
import java.io.BufferedReader;   // 載入java.io.BufferedReader類別
import java.io.InputStreamReader;// 載入java.io.InputStreamReader類別
import java.io.IOException;      // 載入java.io.IOException類別
public class Ex14_1{
    public static void main(String args[]) throws IOException{
        BufferedReader buf;
        String str;
      
        buf=new BufferedReader(new InputStreamReader(System.in));
      
        System.out.print("Input a string: ");
        str=buf.readLine();  // 將輸入的文字指定給字串變數str存放
      
        System.out.println("string= "+str);   // 印出字串
    }
}

/* output--------------------
Input a string: Hello Java!!
string= Hello Java!!
---------------------------*/