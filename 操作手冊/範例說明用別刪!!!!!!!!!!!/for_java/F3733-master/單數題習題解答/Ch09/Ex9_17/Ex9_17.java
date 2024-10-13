// Ex9_17, 利用for迴圈建立物件
class CCircle{
   private static double pi=3.14;
   private double radius;
   
   public CCircle(double r)   {
      radius=r;
   }
   public void show(){
      System.out.println("area="+pi*radius*radius);
   }
}
public class Ex9_17
{
   public static void main(String[] args){
      CCircle cir[];
      cir=new CCircle[3];
      double[] radius={1.0,4.0,2.0};
      for(int i=0;i<cir.length;i++)      {
         cir[i]=new CCircle(radius[i]);
         cir[i].show();
      }
   }
}

/* output-----
area=3.14
area=50.24
area=12.56
------------*/ 