// Ex10_17
class Truck{
    protected String name="Toyota";   
 }
 

public class Ex10_17{
   public static void main(String[] args){
      Truck t1=new Truck();
      System.out.println(t1.getClass());
   }
}

/* output-----
class Truck
------------*/