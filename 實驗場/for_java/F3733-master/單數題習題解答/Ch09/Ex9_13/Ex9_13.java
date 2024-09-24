// Ex9_13, 分數的四則運算
class Fraction{   // 分數類別   
   private int num,den;

   public Fraction(int n,int d){
      num=n;
      den=d;
   }
   public void setN(int n) { 	// 設定分子      
      num=n;
   }
   public void setD(int d){	// 設定分母     
      den=d; 
   }      
   public void setND(int n,int d){
      num=n;
      den=d;
   }    
   public void show(){
      System.out.println(num+"/"+den);   // 顯示分數
   }   
   public Fraction add(Fraction f){
      int new_num=this.num*f.den+this.den*f.num;
      int new_den=this.den*f.den;
      return new Fraction(new_num,new_den);
   }

}
public class Ex9_13{
   public static void main(String[] args){
      Fraction f1=new Fraction(3,5);
      Fraction f2=new Fraction(1,4);
      Fraction result= f1.add(f2);
      result.show();
   }
}

/* output----
17/20
-----------*/