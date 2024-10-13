// Ch12_2, package的使用(一),此檔案置於pack2資料夾內
package pack2;	// 宣告以下程式碼所定義的類別均納入package pack2中
class Circle{	// Circle類別已納入package pack2中
   public void show(){
      System.out.println("show() called");
   }
}
public class Ch12_2{    // Ch12_2類別也納入package pack2中
   public static void main(String args[]){
      Circle c1=new Circle(); 
      c1.show();
   }
}