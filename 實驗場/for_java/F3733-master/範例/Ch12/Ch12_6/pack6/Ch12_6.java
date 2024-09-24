// Ch12_6.java,此檔案置於pack6資料夾內
package pack6;  // 將Ch12_6類別納入package pack6當中
import pack6.subpack1.Circle;  	// 載入pack6.subpack1裡的Circle類別
import pack6.subpack2.Rectangle;	// 載入pack6.subpack2裡的Rectangle類別

public class Ch12_6{
   public static void main(String[] args){
      Circle c1=new Circle();  
      Rectangle r1=new Rectangle();
      c1.show();
      r1.show();
   }
}