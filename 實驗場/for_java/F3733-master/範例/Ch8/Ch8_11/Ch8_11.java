// Ch8_11, 函數的多載(二)
class Circle{  						
    String color;
    double pi=3.14;
    double radius;
 
    void setCircle(String str){ 		// 設定color成員       
        color=str;
    }
    void setCircle(double r){     		// 設定radius成員       
        radius=r;
    }   
    void setCircle(String str, double r){	// 同時設定color與radius       
        color=str;    
        radius=r;
    }      
    void show(){                  // 列印半徑、顏色與圓面積   
        System.out.printf("color=%s, Radius=%5.2f\n",color,radius);
        System.out.printf("area=%6.2f\n",pi*radius*radius);
    }
}
public class Ch8_11{
    public static void main(String[] args){
        Circle c1=new Circle();
        c1.setCircle("Red");		// 呼叫第7行的setCircle() 
        c1.setCircle(2.0); 		// 呼叫第10行的setCircle()
        c1.show();
    
        c1.setCircle("Blue",4.0);	// 呼叫第13行的setCircle() 
        c1.show();     
    }
}  