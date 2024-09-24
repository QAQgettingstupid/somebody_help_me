// Ex10_7
class Caaa{
   public void display(){
      System.out.println("printed from Caaa class");
   }
}
class Cbbb extends Caaa{
   public void display(){
      System.out.println("printed from Cbbb class");
   }
}
public class Ex10_7
{
   public static void main(String[] args){
      Caaa bb=new Cbbb();
      bb.display();
   }
}

/* output----------------
printed from Cbbb class
-----------------------*/