// Ch8_14, 公有成員(函數)的建立
class Circle{   				// 定義類別Circle
    private double pi=3.14;    	// 將資料成員設定為private
    private double radius;
  
    private double area(){		// 私有的函數成員area()   
        return pi*radius*radius;
    }
    public void show_area(){   	// 公有的函數成員show_area()      
        System.out.printf("area=%6.2f", area());  // 呼叫私有成員area()
    }
    public void setRadius(double r) {  // 定義公有的函數成員setRadius()     
        if(r>0) {       
            radius=r;      		// 將私有成員radius設為r
            System.out.printf("radius=%5.2f",radius);
        }
        else
            System.out.println("input error");
    }  
}
public class Ch8_14{
    public static void main(String args[]){
        Circle c1=new Circle();  
        c1.setRadius(-2.0);	  // 呼叫公有的setRadius() 函數
        c1.show_area();      	  // 呼叫公有的show_area() 函數
    }
}