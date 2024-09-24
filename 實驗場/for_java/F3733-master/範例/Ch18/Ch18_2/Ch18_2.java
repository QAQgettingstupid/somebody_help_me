// Ch18_2, 取得本機的名稱與IP位址
import java.net.*;
public class Ch18_2{
    public static void main(String args[]){
        try{
            InetAddress adr;      // 宣告InetAddress類別型態的變數adr
            adr=InetAddress.getByName("udn.com");	// 取得IP位址
            System.out.println(adr);
        }
        catch(UnknownHostException e){
            System.out.println("無法取得IP位址");
        }
    }
}