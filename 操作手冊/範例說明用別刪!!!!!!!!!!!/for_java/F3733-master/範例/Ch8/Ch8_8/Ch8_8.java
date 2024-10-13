// Ch8_8, 圓形類別Circle
class Circle{
    double pi;
    double radius;
 
    void show_area(){     	// show_area() 函數, 顯示出圓面積
        System.out.printf("area=%6.2f",pi*radius*radius);
    }
    void setCircle(double p,double r){  	// 擁有兩個引數的函數
        pi=p;
        radius=r;   
    }
}
public class Ch8_8{
    public static void main(String[] args){
        Circle c1=new Circle();   	// 宣告並建立新的物件
        c1.setCircle(3.1416,2.0);	// 呼叫並傳遞引數到setCircle()
        c1.show_area(); 
    }
}
