// Ch8_5, 資料成員於記憶體內的配置關係
class Circle{   		// 定義類別Circle
    double pi=3.14;		// 設定資料成員的初值
    double radius;
  
    void show_area(){		// show_area() 函數, 顯示出圓面積   	
        System.out.printf("pi=%5.2f, area=%6.2f\n",pi,pi*radius*radius);
    }
}
public class Ch8_5{
    public static void main(String[] args){
        Circle c1=new Circle();		// 建立c1物件
        Circle c2=new Circle();		// 建立c2物件

        c1.radius=c2.radius=2.0;		// 設定資料成員的值
        c2.pi=3.0;            			// 更改c2的pi值
        c1.show_area();
        c2.show_area();          
    }
}