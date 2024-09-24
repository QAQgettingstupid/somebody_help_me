// Ex10_3
class Rectangle{
   private int length;
   private int width;

   public Rectangle(){
      length=2;
      width=2;
   }
   public Rectangle(int len,int wid){
      length=len;
      width=wid;
   }
   private void show(){
       System.out.print("length="+length);
       System.out.print(", width="+width);
   }
   public void area(){
      show();
      System.out.println(", area="+length*width);
   }
}

class Data extends Rectangle{
   public Data(){
   }
   public Data(int len,int wid){
      super(len,wid);
   }
}

public class Ex10_3{
   public static void main(String args[])
   {
      Data obj1=new Data(3,8);
      Data obj2=new Data();
      obj1.area();
      obj2.area();
   }
}

/* output-------------------
length=3, width=8, area=24
length=2, width=2, area=4
--------------------------*/