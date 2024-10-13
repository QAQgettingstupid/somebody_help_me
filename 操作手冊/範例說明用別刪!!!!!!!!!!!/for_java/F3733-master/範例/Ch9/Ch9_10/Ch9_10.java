// Ch9_10, 傳遞物件變數
class Circle{
    private static double pi=3.14; 
    private double radius;
 
    public Circle(double r){ 		  // Circle()建構子
        radius=r;
    }
    public void compare(Circle cir){ 	// compare() 函數 
        if(this.radius==cir.radius)    	// 判別物件的radius成員是否相等
            System.out.println("Radius are equal");
        else
            System.out.println("Radius are not equal"); 
    }         
}
public class Ch9_10{
    public static void main(String[] args){
        Circle c1=new Circle(1.0);
        Circle c2=new Circle(2.0);      
        c1.compare(c2);   	// 比較c1與c2的radius是否相等
    }
}