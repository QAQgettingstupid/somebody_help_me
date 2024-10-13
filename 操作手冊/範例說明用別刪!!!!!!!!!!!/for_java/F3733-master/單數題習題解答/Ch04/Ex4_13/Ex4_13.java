import java.util.Scanner;
public class Ex4_13{
    public static void main(String[] args){
        Scanner scn=new Scanner(System.in);
        
        System.out.print("Input radius:");
        double r=scn.nextDouble();                
        System.out.printf("volume=%7.2f\n",(4.0/3.0*3.14*r*r*r));
        scn.close();
    }
}

/* output----------
Input radius:10
volume=4186.67
-----------------*/