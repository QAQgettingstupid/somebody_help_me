// Ch8_4, 圓形類別Circle
class Circle{   		// 定義類別Circle
    double pi=3.14;		// 將資料成員pi設定初值
    double radius;
   
    void show_area(){	// show_area() 函數, 顯示出圓面積
        System.out.printf("area=%6.2f",pi*radius*radius);
    }
}
public class Ch8_4{
    public static void main(String[] args){
        Circle c1=new Circle();	// 建立cirl物件
        c1.radius=2.0;			// 設定radius的值
        c1.show_area();			// 呼叫show_area() 函數
    }
} 