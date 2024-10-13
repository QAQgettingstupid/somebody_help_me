// ex9_7, 計算1+2+3+...+n
class Summation{  
   public static void add(int n){
      int sum=0;
      for(int i=1;i<=n;i++)
         sum+=i;
      System.out.println("1+2+...+"+n+"="+sum);
   }
}

public class Ex9_7{
   public static void main(String[] args){   
      Summation.add(5);
      Summation.add(10);
   }
}

/* output-------
1+2+...+5=15
1+2+...+10=55
--------------*/ 