// Ch10_6, 函數的「改寫」範例
class Circle{   			// 父類別Circle
    protected static double pi=3.14;
    protected double radius;
    
    public Circle(double r){   
       radius=r;
    }
    public void show(){      	// 父類別裡的show() 函數   
       System.out.println("radius="+radius);
    }
}   
class Coin extends Circle{   // 子類別Coin
    private int value;
    
    public Coin(double r,int v){   
       super(r);
       value=v;
    }
    public void show(){      	// 子類別裡的show() 函數   
       System.out.println("radius="+radius+", value="+value);
    }
}
public class Ch10_6{
    public static void main(String[] args){
       Coin coin=new Coin(2.0,5);
       coin.show();			// 呼叫show() 函數
    }
}
  