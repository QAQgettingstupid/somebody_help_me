// Ch10_2, 呼叫父類別中特定的建構子
class Circle{   				// 定義父類別Circle
    private static double pi=3.14;
    private double radius;
  
    public Circle(){ 			// 父類別裡沒有引數的建構子   
       System.out.println("Circle() constructor called");
    }
    public Circle(double r) {	// 父類別裡有一個引數的建構子      
       System.out.println("Circle(double r) constructor called");
       radius=r;      
    }   
    public void show(){    
       System.out.printf("area=%6.2f\n",pi*radius*radius);
    }
}
class Coin extends Circle{  // 定義子類別Coin，繼承自Circle類別
    private int value;
    public Coin(){    		 		// 子類別裡沒有引數的建構子 
       System.out.println("Coin() constructor called");
    } 
    public Coin(double r, int v){		// 子類別裡有兩個引數的建構子 
       super(r);   // 呼叫父類別裡有引數的建構子，即第9行所定義的建構子
       value=v;      
       System.out.println("Coin(double r, int v) constructor called");
    }    
}
public class Ch10_2{
    public static void main(String[] args)   {
       Coin coin1=new Coin();	     		// 建立物件，並呼叫第19行的建構子
       Coin coin2=new Coin(2.5,10);	// 建立物件，並呼叫第22行的建構子 
       coin1.show();
       coin2.show();
    }
} 