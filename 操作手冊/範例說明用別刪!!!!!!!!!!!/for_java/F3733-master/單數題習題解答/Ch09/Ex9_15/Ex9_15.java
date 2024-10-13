// Ex9_15, 傳回較大的分數
class Fraction{   // 分數類別   
   private int num,den;

   public Fraction(int n,int d){
      num=n;
      den=d;
   }
   public void show(){
      System.out.println(num+"/"+den);   // 顯示分數
   }

   public boolean larger(Fraction f){
      if((double)this.num/this.den > (double)f.num/f.den)
         return true;
      else 
         return false;
   }
}
public class Ex9_15{
   public static void main(String[] args){
      Fraction f1=new Fraction(2,3);
      Fraction f2=new Fraction(1,2);
      if(f1.larger(f2))
         System.out.println("f1 is larger");
      else 
         System.out.println("f2 is larger");
   }
}

/* output------
f1 is larger
-------------*/