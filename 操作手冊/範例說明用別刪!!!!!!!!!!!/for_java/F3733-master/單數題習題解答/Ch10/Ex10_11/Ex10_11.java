// Ex10_11
class Caaa{
   public int n1,n2;
   public Caaa(){
      n1=n2=1;
   }
   public Caaa(int a,int b){
      n1=a; n2=b;
   }
   public void show(){
      System.out.println("n1="+n1+", n2="+n2);
   }    
}
class Cbbb extends Caaa{
   public Cbbb(){
      super();
   }
   public Cbbb(int a1, int a2){
      super(a1,a2);
   }
}
 
public class Ex10_11{
   public static void main(String[] args){
      Cbbb b1=new Cbbb();
      b1.show();
      Cbbb b2=new Cbbb(2,5);
      b2.show();
   }
} 

/* output----------------
n1=1, n2=1
n1=2, n2=5
-----------------------*/