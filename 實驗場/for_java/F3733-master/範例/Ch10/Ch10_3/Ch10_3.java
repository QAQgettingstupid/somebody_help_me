// Ch10_3, 建構子錯誤的範例
class Circle{   				// 定義類別Circle
    private static double pi=3.14;
    private double radius;
  
    public Circle(double r){		// 有引數的建構子   
       radius=r;      
    }
    public void setRadius(double r){
       radius=r;         
       System.out.println("radius="+radius);
    }
} 
class Coin extends Circle{  		// 定義Coin類別，繼承自Circle類別
    private int value;
 
    public Coin(double r, int v) {    // Coin()有兩個引數的建構子      
       setRadius(r);  	// 透過setRadius() 函數來設定radius成員
       value=v;        	// 設定value成員
    }    
}
public class Ch10_3{
    public static void main(String[] args){
       Coin coin1=new Coin(2.5,10); // 建立物件，並呼叫有兩個引數的建構子
    }
}
 