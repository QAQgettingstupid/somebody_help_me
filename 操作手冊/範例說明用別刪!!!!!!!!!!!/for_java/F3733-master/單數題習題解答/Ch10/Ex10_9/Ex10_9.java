// Ex10_9
class Shape{
   public double area(){
     return 0.0;
   }
}
class Circle extends Shape{
   double radius;
   public Circle(double r){
      radius=r;
   }
   public double area(){
      return (3.14*radius*radius);
   }
}
class Square extends Shape{
   double side;
   public Square(double s){
      side=s;
   }
   public double area(){
      return (side*side);
   }
}
class Triangle extends Shape{
   double base,height;
   public Triangle(double b,double h){
      base=b;
      height=h;
   }
   public double area(){
      return (base*height/2);
   }
}
public class Ex10_9{
   public static void main(String[] args){
      Circle cir1=new Circle(1.0);
      Circle cir2=new Circle(2.0);
      Square squ1=new Square(1.0);
      Square squ2=new Square(2.0);
      Triangle tri1=new Triangle(3,6);
      Triangle tri2=new Triangle(4,10);
      double a[]=new double[6];

      System.out.println("circle(1.0)="+cir1.area());
      System.out.println("circle(2.0)="+cir2.area());
      System.out.println("square(1.0)="+squ1.area());
      System.out.println("square(2.0)="+squ2.area());
      System.out.println("triangle(3,6)="+tri1.area());
      System.out.println("triangle(4,10)="+tri2.area());

      a[0]=cir1.area();
      a[1]=cir2.area();
      a[2]=squ1.area();
      a[3]=squ2.area();
      a[4]=tri1.area();
      a[5]=tri2.area();
      System.out.println("The largest area is "+largest(a));
   }
   public static double largest(double a[]){
     double max=a[0];
     for(int i=0;i<a.length;i++)
        if(max<a[i])
           max=a[i];
     return max;
   }
}

/* output-----------------
circle(1.0)=3.14
circle(2.0)=12.56
square(1.0)=1.0
square(2.0)=4.0
triangle(3,6)=9.0
triangle(4,10)=20.0
The largest area is 20.0
------------------------*/