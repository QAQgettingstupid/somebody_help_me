// Ex11_3, 抽象類別
abstract class Shape{
    protected int width;
    protected int height; 
 
    public void show(){
       System.out.println("width="+width);
       System.out.println("height="+height);
       System.out.println("area="+area());
    }
    public abstract int area();    // 計算面積  
}
class Win extends Shape{      
    public Win(int w,int h){
        width=w;
        height=h;      
    }     
    public int area(){
        return width*height;
    }
}
 
public class Ex11_3{
    public static void main(String args[]){
       Win w=new Win(5,7); 	// 建立Win類別的物件
       w.show();
    }
}

/* output----
width=5
height=7
area=35
-----------*/ 