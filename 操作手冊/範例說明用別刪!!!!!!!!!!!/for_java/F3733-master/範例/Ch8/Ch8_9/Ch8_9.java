// Ch8_9, 圓形類別Circle
class Circle{   			// 定義類別Circle
    double pi;    			// 將資料成員設定初值
    double radius;
 
    double getRadius(){		// getRadius(), 用來傳回物件的半徑     
        return radius;
    }
    void setCircle( double p, double r){
        pi=p;
        radius=r;   
    }
}
public class Ch8_9{
    public static void main(String[] args){
        Circle c1=new Circle();   	// 宣告並建立新的物件
        c1.setCircle(3.1416,2.0);
        System.out.printf("radius=%5.2f",c1.getRadius()); 
    }
}  
