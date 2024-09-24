// Ch9_4, 公有與私有建構子的比較
class Circle{   				// 定義類別Circle
    private String color;
    private double pi=3.14;
    private double radius;
 
    private Circle(){     				// 私有建構子
        System.out.println("Private constructor called"); 
    }   
    public Circle(String str, double r){ 	// 公有建構子
        this();
        color=str; 
        radius=r;
    }      
    public void show(){ 
        System.out.printf("color=%s, Radius=%5.2f\n",color,radius);
        System.out.printf("area=%6.2f\n",pi*radius*radius);
    }
}
public class Ch9_4{
    public static void main(String[] args){
        Circle c1=new Circle("Blue",1.0);
        c1.show();
    }
}