// Ch9_15, 內部類別的使用
public class Ch9_15{
    public static void main(String[] args){  
        Circle c1=new Circle();
        c1.set_radius(5.2);
    }
    static class Circle{
        private double radius;
        void set_radius(double r){
            radius=r;
            System.out.printf("radius=%5.2f",radius); 
        }
    }
}