// Ch9_8, 設值給物件變數
class Circle{   		// 定義類別Circle
    private static double pi=3.14;   
    private double radius;
 
    public Circle(double r){         
        radius=r;
    }      
    public void show(){           
        System.out.printf("area=%6.2f\n",pi*radius*radius);
    }
}
public class Ch9_8{
    public static void main(String[] args){
        Circle c1,c2;		// 宣告c1,c2為物件變數
        c1=new Circle(1.0);	// 建立新的物件，並將c1指向它
        c1.show();  
      
        c2=c1;    // 將c1設給c2，此時這兩個變數所指向的內容均相等
        c2.show();
      
        Circle c3=new Circle(2.0); // 建立新的物件，並將c3指向它
        c3.show();
    }
}