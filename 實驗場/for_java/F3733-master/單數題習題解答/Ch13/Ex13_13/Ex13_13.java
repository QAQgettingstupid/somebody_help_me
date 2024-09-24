// Ex13_13
class OutException extends Exception{}
class InException extends Exception{}
class CenterException extends Exception{}
class Circle{
    private double radius=10.0;
    private double x1;
    private double y1;
    private double x2;
    private double y2;
    double dist;
   
    public Circle(double a,double b,double c,double d){
        x1=a;
        y1=b;
        x2=c;
        y2=d;
    }
    public void check(){
        dist=Math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));      
        try{
            if(x1==x2 && y1==y2)
                throw new CenterException();
            else if(dist<=radius)
                throw new InException();
            else if(dist>radius)
                throw new OutException();         
        }
        catch(CenterException e){
            System.out.print("("+x1+","+y1+")");
            System.out.print("在半徑"+radius);
            System.out.println(",圓心("+x2+","+y2+")的圓心上");  
        }      
        catch(OutException e){
           System.out.print("("+x1+","+y1+")");
           System.out.print("不在半徑"+radius);
           System.out.println(",圓心("+x2+","+y2+")的圓內");  
        }
        catch(InException e){
           System.out.print("("+x1+","+y1+")");
           System.out.print("在半徑"+radius);
           System.out.println(",圓心("+x2+","+y2+")的圓內");
        }
    }     
}
public class Ex13_13{
    public static void main(String args[]){
        Circle c1=new Circle(5.8,2.1,0.2,9.5);
        c1.check();
    }
}  

/* output-----------------------------------
(5.8,2.1)在半徑10.0,圓心(0.2,9.5)的圓內
------------------------------------------*/