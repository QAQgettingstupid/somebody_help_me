// Ex9_3, 從某一建構子呼叫另一建構子
class Caaa{
   private int value;
   
   public Caaa(){
      value=1;   
   }
   public Caaa(int i){
      value=i;
   }
   void set_value(int n){
      value=n;
   }
   int get_value(){
      return value;
   }
}
public class Ex9_3{
   public static void main(String args[]){
      Caaa obj1=new Caaa();
      Caaa obj2=new Caaa(12);
      System.out.printf("obj1.value= %d\n",obj1.get_value());
      System.out.printf("obj2.value= %d\n",obj2.get_value());
      obj1.set_value(30);
      obj2.set_value(150);
      System.out.printf("obj1.value= %d\n",obj1.get_value());
      System.out.printf("obj2.value= %d\n",obj2.get_value()); 

   }
}

/* output------
obj1.value= 1
obj2.value= 12
obj1.value= 30
obj2.value= 150
---------------*/ 