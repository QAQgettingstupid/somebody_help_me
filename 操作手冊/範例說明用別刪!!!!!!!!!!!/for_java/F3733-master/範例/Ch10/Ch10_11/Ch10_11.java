// Ch10_11, 利用getClass()取得呼叫物件所屬的類別
class Caaa{     		// 定義Caaa類別
}   
public class Ch10_11{
   public static void main(String[] args){
      Caaa a=new Caaa();
      System.out.println(a.getClass());  // 印出物件a所屬的類別
   }
}