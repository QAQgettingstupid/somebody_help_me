// Ch9_11, 由函數傳回物件變數
class Circle{
    private static double pi=3.14;   
    private double radius;
 
    public Circle(double r) { 	// Circle建構子   
        radius=r;
    }
    public Circle compare(Circle cir) { // Compare() 函數            
        if(this.radius>cir.radius) 
            return this;			// 傳回呼叫compare() 函數的物件
        else
            return cir;      		// 傳回傳入compare() 函數的物件
    }         
}
public class Ch9_11{
    public static void main(String[] args){   
        Circle c1=new Circle(1.0);
        Circle c2=new Circle(2.0);
        Circle obj;     

        obj=c1.compare(c2);      // 呼叫compare() 函數
        if(c1==obj)
            System.out.println("radius of c1 is larger");
        else
            System.out.println("radius of c2 is larger");
    }
} 