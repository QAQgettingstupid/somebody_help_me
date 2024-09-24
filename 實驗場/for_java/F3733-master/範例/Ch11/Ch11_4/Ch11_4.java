// Ch11_4, 介面的實作範例
interface iShape2D{   			   // 定義介面 
   final double PI=3.14;
   abstract void area();
}

class Rectangle implements iShape2D{ // 以Rectangle類別實作iShape2D介面
   int width,height;
   public Rectangle(int w,int h){
      width=w;
      height=h;
   }
   public void area(){   	// 定義area()的處理方式
      System.out.println("area="+width*height);      
   }
}

class Circle implements iShape2D{    // 以Circle類別實作iShape2D介面
   double radius;
   public Circle(double r){
      radius=r;
   }
   public void area(){     	// 定義area()的處理方式   
      System.out.println("area="+PI*radius*radius);      
   }
}

public class Ch11_4{
   public static void main(String[] args){
      Rectangle r1=new Rectangle(5,10);  
      r1.area();   		// 呼叫Rectangle類別裡的area()
      
      Circle c1=new Circle(2.0);  
      c1.area();  		// 呼叫Circle類別裡的area()
   }
}