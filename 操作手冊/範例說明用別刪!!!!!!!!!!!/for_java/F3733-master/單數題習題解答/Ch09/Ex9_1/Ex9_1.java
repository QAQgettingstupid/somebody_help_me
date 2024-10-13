// Ex9_1
class Rectangle{
   int width;
   int height;
   
   public Rectangle(int w,int h){
      width=w;
      height=h;
      System.out.println("constructor CRectangle(int w,int h) called");
   }
   public Rectangle(){
      width=1;
      height=1;
      System.out.println("constructor CRectangle() called");
   }
   public void show(){
      System.out.println("width="+width);
      System.out.println("height="+height);
   }
}

public class Ex9_1{
   public static void main(String[] args){
      Rectangle rec1=new Rectangle(5,2);
      rec1.show();
      Rectangle rec2=new Rectangle();
      rec2.show();
   }
}

/* output-------------------------------------
constructor CRectangle(int w,int h) called
width=5
height=2
constructor CRectangle() called
width=1
height=1
--------------------------------------------*/ 