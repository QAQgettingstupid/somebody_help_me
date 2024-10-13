// Ch10_5, protected成員的使用
class Circle{
    protected static double pi=3.14;	// 將pi宣告成protected
    protected double radius;			// 將radius宣告成protected
  
    public void show(){
       System.out.printf("area=%6.2f",pi*radius*radius);
    }
}
class Coin extends Circle{   // 定義Coin類別，繼承自Circle類別
    private int value;
 
    public Coin(double r, int v){    
       radius=r;   	// 在子類別裡可直接取用父類別裡的protected成員
       value=v;      
       System.out.println("radius="+radius+", value="+value);
    }    
}
public class Ch10_5{
    public static void main(String[] args){
       Coin coin=new Coin(2.5,10);  
       coin.show();
    }
} 