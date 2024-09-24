// Ch9_14, 類別的複習
class Circle{
    private double radius;
    void set_radius(double r){
        radius=r;
        System.out.printf("radius=%5.2f",radius); 
    }
}
public class Ch9_14{
    public static void main(String[] args){  
        Circle c1=new Circle();
        c1.set_radius(5.2);
    }
}