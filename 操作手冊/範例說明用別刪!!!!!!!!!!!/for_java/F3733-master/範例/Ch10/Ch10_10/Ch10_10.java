// Ch10_10, 設定終止繼承
class Caaa{  
    public final void show(){	// 父類別的show()已被設為終止繼承   
       System.out.println("show() 函數 in class Caaa called");
    }
}
class Cbbb extends Caaa{
    public void show(){    		// 錯誤，改寫父類別的show() 函數    
       System.out.println("show() 函數 in class Cbbb called");
    }
}
public class Ch10_10{
    public static void main(String[] args){
       Cbbb b=new Cbbb();
       b.show();
    }
}
 