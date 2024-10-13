// Ex11_13
interface iVolume{
    public void showData();    		// 顯示球體的資料
    public double vol();       		// 計算球體積
}
abstract class Sphere implements iVolume{   
    final double PI=3.14;
    protected int x;
    protected int y;
    protected int radius;
    public void showData(){
        System.out.println("球心:("+x+","+y+")");
        System.out.println("半徑:"+radius);
        System.out.printf("球體積:%5.2f\n",vol());
    }
    public double vol(){
        return ((4.0/3)*PI*radius*radius*radius);
    }
}
class Circle extends Sphere{
    public Circle(int a,int b,int r){
        x=a;
        y=b;
        radius=r;
    }    
}
 
public class Ex11_13{
    public static void main(String[] args){
       Circle c1=new Circle(8,6,2);          
       c1.showData();
    }
}

/* output-----
球心:(8,6)
半徑:2
球體積:33.49  
------------*/