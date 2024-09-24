// Ch8_13, 私有成員無法從類別外部來存取的範例
class Circle{   				// 設定field為私有成員
    private double pi=3.14;    	// 將資料成員設定初值
    private double radius;
   
    void show_area(){     
        System.out.printf("area=%6.2f\n",pi*radius*radius);
    }
}
public class Ch8_13{
    public static void main(String args[]){
        Circle c1=new Circle();
        c1.radius=-2.0;
        c1.show_area();
    }
}