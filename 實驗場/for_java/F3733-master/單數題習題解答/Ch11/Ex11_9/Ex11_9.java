// Ex11_9, 多重繼承的練習
interface iShape{   
    public void show();  
    public int area(); 
}
interface iColor{
    public void showColor();
}
 
class Win implements iShape,iColor{
    protected int width;
    protected int height;
    protected String color;
    
    public Win(int w,int h,String str){
        width=w;
        height=h;
        color=str;      
    }
    public void show(){
        showColor();
        System.out.println("width="+width);
        System.out.println("height="+height);
        System.out.println("area="+area());
    }
    public int area(){
        return width*height;
    }
    public void showColor(){
        System.out.println("color="+color);
    }
}
 
public class Ex11_9{
    public static void main(String args[]){
        Win w=new Win(5,7,"Green");
        w.show();
    }
}

/* output-----
color=Green
width=5
height=7
area=35
------------*/