class CShpere{    
    private int x;    
    private int y; 
    private int z; 
    private int r;
    private double pi=3.14;    

    void setLocation(int a, int b, int c){
        x=a;
        y=b;
        z=c;
    }
    void setRadius(int radius){
        r=radius;
    }
    double surfaceArea(){
        return 4*pi*r*r;
    }
    double volume(){
        return (double)4/3*pi*r*r*r;
    }
    void showCenter(){
        System.out.println("圓心座標:("+x+","+y+","+z+")");
    }
}
public class Ex8_15{
    public static void main(String[] args){ 
        CShpere obj=new CShpere();
        obj.setLocation(3,4,5);
        obj.setRadius(1);
        System.out.println("表面積="+obj.surfaceArea());
        System.out.println("體積="+obj.volume());
        obj.showCenter();
    }
}

/* output-----------------
表面積=12.56
體積=4.1866666666666665
圓心座標:(3,4,5)
------------------------*/