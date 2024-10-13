// Ch9_16, 於外部類別內取用內部類別的成員
class Circle{   // 外部類別
    private double radius;
    private Color clr;
   
    public Circle(double r, String c){
        radius=r;
        clr=new Color(c);
        System.out.println("Circle() 建構子被呼叫了"); 
    }
    public void show(){
        System.out.printf("radius=%5.2f, color= %s\n",radius,clr.color);
    }
    private class Color{     // Circle的內部類別
        private String color;
        Color(String c){
            color=c;
            System.out.println("Color() 建構子被呼叫了"); 
        }
    }
}
public class Ch9_16{
    public static void main(String[] args){  
        Circle c1=new Circle(2.0,"Blue");
        c1.show();
    }
}