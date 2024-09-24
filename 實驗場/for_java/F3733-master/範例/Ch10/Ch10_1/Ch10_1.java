// Ch10_1, 簡單的繼承範例
class Circle{			// 父類別Circle
    private static double pi=3.14;
    private double radius;
  
    public Circle(){	// Circle()建構子       
       System.out.println("Circle() constructor called ");
    }    
    public void setRadius(double r){   
       radius=r;
       System.out.println("radius="+radius);      
    }
    public void show(){    
       System.out.printf("area=%6.2f\n",pi*radius*radius);
    }
}
class Coin extends Circle{		// 子類別Coin，繼承自Circle類別
    private int value;			// 子類別的資料成員
    
    public Coin(){				// 子類別的建構子   
       System.out.println("Coin() constructor called ");
    } 
    public void setValue(int t){	// 子類別的setValue() 函數   
       value=t;
       System.out.println("value="+value);
    }      
}
public class Ch10_1{
    public static void main(String[] args){
       Coin coin=new Coin();	// 建立coin物件
       coin.setRadius(2.0);	// 呼叫由父類別繼承而來的setRadius()
       coin.show();			// 呼叫由父類別繼承而來的show()
       coin.setValue(5);     	// 呼叫子類別的setValue()
    }
}  
  