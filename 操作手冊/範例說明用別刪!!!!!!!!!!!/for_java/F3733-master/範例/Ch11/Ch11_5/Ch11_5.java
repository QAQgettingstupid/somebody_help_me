// Ch11_5,透過介面型態的變數來存取物件
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
 
public class Ch11_5{
    public static void main(String[] args){
       iShape2D v1,v2; 	// 宣告介面型態的變數
       v1=new Rectangle(5,10); // 將介面型態的變數v1指向新建的物件
       v1.area();   	// 透過介面v1呼叫show() 函數
       
       v2=new Circle(2.0);	// 將介面型態的變數v2指向新建的物件
       v2.area();                	// 透過介面v2呼叫show() 函數
    }
}
 