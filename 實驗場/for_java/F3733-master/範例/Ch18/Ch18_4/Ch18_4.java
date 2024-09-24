// Ch18_4, 載入URL的檔案內容
import java.net.*;
import java.io.*;
public class Ch18_4{
    public static void main(String args[]){
        String str;
        try{
            URL u=new URL("https://flagtech.github.io/flag.txt");

            Object obj=u.getContent();    			// 取得URL的內容
            InputStreamReader isr=new InputStreamReader((InputStream) obj);
            BufferedReader br=new BufferedReader(isr);

            while((str=br.readLine())!=null)
                System.out.println(str);
            br.close();
        }
        catch(IOException e){
            System.out.println("發生了"+e+"例外");
        }
    }
}