// Ch10_4, 修正Ch10_3的錯誤
class Circle{   				// 定義類別Circle
    private double pi=3.14;
    private double radius;
  
    public Circle(){           	// 沒有引數的建構子       
    }    
    public Circle(double r) { 	// 有一個引數的建構子   
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
 public class Ch10_4{
    public static void main(String[] args){
       Coin coin1=new Coin(2.5,10); // 建立物件，並呼叫有兩個引數的建構子
    }
 }
   