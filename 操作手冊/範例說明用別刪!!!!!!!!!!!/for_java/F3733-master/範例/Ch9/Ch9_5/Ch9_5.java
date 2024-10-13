// Ch9_5, 簡單的範例:實例變數與實例函數
class Circle{
    private double pi=3.14;
    private double radius;
 
    public Circle(double r){	   // Circle()建構子 
        radius=r;
    } 
    public void show(){ 
        System.out.printf("area=%6.2f\n",pi*radius*radius);
    }
}
public class Ch9_5{
    public static void main(String[] args){
        Circle c1=new Circle(1.0);
        c1.show();		 	// show()必須透過物件來呼叫
        Circle c2=new Circle(2.0);
        c2.show();		 	// show()必須透過物件來呼叫
    }
}