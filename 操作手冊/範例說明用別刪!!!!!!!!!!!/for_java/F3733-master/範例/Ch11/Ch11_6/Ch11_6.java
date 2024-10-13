// Ch11_6, 用Circle類別實作兩個以上的介面
interface iShape2D{   		// 定義iShape2D介面
    final double PI=3.14;
    abstract void area();
}
 
 interface iColor{   		// 定義iColor介面
    abstract void setColor(String str);
}
 
class Circle implements iShape2D,iColor{   // 實作iShape2D與iColor介面
    double radius;
    String color;
    public Circle(double r){
       radius=r;
    }
    public void setColor(String str){      // 定義iColor介面裡的setColor()   
       color=str;
       System.out.println("color="+color); 
    }
    public void area(){     	// 定義iShape2D介面裡的area() 函數   
       System.out.println("area="+PI*radius*radius);
    }
}
public class Ch11_6{
    public static void main(String args[]){
       Circle c1;
       c1=new Circle(2.0); 
       c1.setColor("Blue");		// 呼叫setColor()
       c1.area(); 			     // 呼叫show()
    }
}
 