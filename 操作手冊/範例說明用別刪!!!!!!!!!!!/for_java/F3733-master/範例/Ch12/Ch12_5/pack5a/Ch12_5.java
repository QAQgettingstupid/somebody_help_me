// Ch12_5.java, package的使用(四),此檔案置於pack5a資料夾內
package pack5a;
import pack5b.Circle;   // 載入pack5b package裡的Circle類別
public class Ch12_5{
   public static void main(String[] args){
      Circle c1=new Circle();  	// 不用再寫package的名稱
      c1.show();
   }
}