// Ch11_7, 介面的延伸
interface iShape{  				// 定義iShape介面
   final double PI=3.14;   
   abstract void setColor(String str);
}

interface iShape2D extends iShape{    // 定義iShape2D介面, 繼承自iShape
   abstract void area();
}

class Circle implements iShape2D{     // 實作iShape2D介面
   double radius;
   String color;

   public Circle(double r){   
      radius=r;
   }
   public void setColor(String str) { 	// 定義iShape介面的setColor()
      color=str;
      System.out.println("color="+color); 
   }
   public void area(){               	// 定義iShape2D介面裡的area()
      System.out.println("area="+PI*radius*radius);      
   }
}
public class Ch11_7{
   public static void main(String args[]){
      Circle c1;
      c1=new Circle(2.0); 
      c1.setColor("Blue");    		// 呼叫setColor()
      c1.area();     				// 呼叫area()
   }
}
