// Ch8_12, 圓形類別Circle
class Circle{   			// 定義類別Circle
    double pi=3.14;    	// 將資料成員設定初值
    double radius;
   
    void show_area(){       
        System.out.printf("area=%6.2f\n",pi*radius*radius);
    }
}
public class Ch8_12{
    public static void main(String[] args){
        Circle c1=new Circle();
        c1.radius=-2.0;
        c1.show_area();
    }
} 
