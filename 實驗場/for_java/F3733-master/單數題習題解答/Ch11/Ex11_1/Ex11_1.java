// ex11_1，抽象類別裡建構元
abstract class Caaa{
    protected int num;
    public Caaa(int n){   // 請在此撰寫類別Caaa的建構元
        num=n;
    }
    public abstract void show();
}
class Cbbb extends Caaa{
    public Cbbb(int n){   // 請在此撰寫類別Cbbb的建構元
        super(n);
    }
    public void show(){   // 請在此撰寫show() method
        System.out.println("num="+num);
    }   
}
public class Ex11_1{
    public static void main(String args[]){
        Cbbb bb=new Cbbb(2); 	// 此行可設定num成員的值為2
        bb.show();				    // 此行可印出 "num=2" 字串
    }
}    
/* output---
num=2
----------*/
