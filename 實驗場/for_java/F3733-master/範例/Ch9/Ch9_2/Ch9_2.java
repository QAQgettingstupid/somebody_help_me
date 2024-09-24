// Ch9_2,建構子的多載
class Circle{   			// 定義類別Circle
    private String color;
    private double pi=3.14;
    private double radius;
 
    public Circle(){        				// 沒有引數的建構子      
        System.out.println("Constructor Circle() called");   
        color="Green";
        radius=1.0;
    }   
    public Circle(String str, double r){   	// 有兩個引數的建構子      
        System.out.println("Constructor Circle(String,double) called"); 
        color=str;    
        radius=r;
    }      
    public void show(){   
        System.out.printf("color=%s, Radius=%5.2f\n",color,radius);
        System.out.printf("area=%6.2f\n",pi*radius*radius);
    }
}
public class Ch9_2{
    public static void main(String[] args){
        Circle c1=new Circle();			// 呼叫沒有引數的建構子
        c1.show();
      
        Circle c2=new Circle("Blue",4.0);	// 呼叫有引數的建構子    
        c2.show();     
    }
} 
