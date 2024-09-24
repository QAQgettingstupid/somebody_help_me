// Ch9_1, 建構子的使用
class Circle{              		// 定義類別Circle
    private double pi=3.14;
    private double radius;
 
    public Circle(double r){      // 定義建構子Circle() 
        radius=r;
    }   
    public void show(){   
        System.out.printf("radius=%5.2f, area=%6.2f",radius,pi*radius*radius);
    }
}
public class Ch9_1{
    public static void main(String[] args){
        Circle c1=new Circle(4.0); 	// 建立物件並呼叫Circle()建構子
        c1.show();
    }
}  
