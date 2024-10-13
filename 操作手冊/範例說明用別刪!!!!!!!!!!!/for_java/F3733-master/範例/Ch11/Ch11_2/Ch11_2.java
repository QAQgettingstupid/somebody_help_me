// Ch11_2, 用抽象類別型態的變數來建立物件
abstract class Shape{    				   // 定義抽象類別Shape    
    protected String color;			      // 資料成員
    public void setColor(String str){ 	// 一般的函數
       color=str;
    }
    public abstract void show(); // 抽象函數，只有定義名稱，沒有定義處理方式
}
 class Rectangle extends Shape{    // 定義子類別Rectangle
    protected int width,height;
    public Rectangle(int w,int h){
       width=w;
       height=h;
    }
    public void show(){   	// 明確定義繼承自抽象類別的show()  
       System.out.print("color="+color+",  ");
       System.out.println("area="+width*height);      
    }
}
 class Circle extends Shape{   	// 定義子類別Circle
    protected double radius;
    public Circle(double r){
       radius=r;
    }
    public void show(){     // 明確定義繼承自抽象類別的show() 
       System.out.print("color="+color+",  ");
       System.out.println("area="+3.14*radius*radius);      
    }
}
public class Ch11_2{
   public static void main(String[] args){
      Shape s1=new Rectangle(5,10); 
      s1.setColor("Yellow");
      s1.show();
      
      Shape s2=new Circle(2.0); 
      s2.setColor("Green"); 
      s2.show(); 
   }
}