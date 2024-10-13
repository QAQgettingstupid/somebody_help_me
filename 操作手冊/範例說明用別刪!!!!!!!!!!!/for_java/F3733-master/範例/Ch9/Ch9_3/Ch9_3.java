// Ch9_3, 從某一建構子呼叫另一建構子
class Circle{   				// 定義類別Circle 
    private String color;
    private double pi=3.14;
    private double radius;
   
    public Circle(){  			// 沒有引數的建構子       
        this("Green",1.0);		// 此行會呼叫第11行的建構子    
        System.out.println("Constructor Circle() called"); 
    }   
    public Circle(String str, double r){    // 有引數的建構子       
        System.out.println("Constructor Circle(String,double) called");
        color=str;    
        radius=r;
    }      
    public void show(){
        System.out.printf("color=%s, Radius=%5.2f\n",color,radius);
        System.out.printf("area=%6.2f\n",pi*radius*radius);
    }
}
public class Ch9_3{
    public static void main(String[] args){
        Circle c1=new Circle();
        c1.show();
    }
} 
