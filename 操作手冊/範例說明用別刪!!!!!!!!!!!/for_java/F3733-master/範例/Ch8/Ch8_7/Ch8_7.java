// Ch8_7, 呼叫函數並傳遞引數
class Circle{   		// 	類別Circle
    double pi=3.14;    	// 將資料成員設定初值
    double radius;
 
    void show_area(){ 	// show_area() 函數, 顯示出半徑及圓面積   
        System.out.printf("radius=%5.2f, ",radius);
        System.out.printf("area=%6.2f\n",pi*radius*radius);
    }
    void setRadius(double r){	// setRadius() 函數, 可用來設定半徑    
        radius=r;          		// 設定radius成員的值為r
    }
}
public class Ch8_7{
    public static void main(String[] args){
        Circle c1=new Circle();   	// 宣告並建立新的物件
        c1.setRadius(4.0);   		// 設定c1的半徑為4.0
        c1.show_area();          
    }
}
