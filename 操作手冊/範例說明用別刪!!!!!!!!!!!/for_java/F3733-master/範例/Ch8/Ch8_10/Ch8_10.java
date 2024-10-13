// Ch8_10, 函數的多載(一)
class Circle{                    
    String color;       			// 資料成員color 
    double pi=3.14;
    double radius;
 
    void setColor(String str){	// 定義設定color的函數   
        color=str;
    }
    void setRadius(double r){	// 定義設定radius的函數   
        radius=r;
    }
    void setAll(String str, double r){  // 同時設定color與radius   
        color=str;    
        radius=r;
    }      
    void show(){                  // 列印半徑、顏色與圓面積   
        System.out.printf("color=%s, Radius=%5.2f\n",color,radius);
        System.out.printf("area=%6.2f\n",pi*radius*radius);
    }
}
public class Ch8_10{
    public static void main(String[] args){
        Circle c1=new Circle();
        c1.setColor("Red");        // 設定c1的color
        c1.setRadius(2.0);         // 設定c1的radius
        c1.show();

        c1.setAll("Blue",4.0);     // 同時設定c1的color和radius
        c1.show();     
    }
}