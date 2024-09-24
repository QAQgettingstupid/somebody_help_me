import java.util.Scanner;
public class Ex4_11{
    public static void main(String[] args){
        Scanner scn=new Scanner(System.in);
        
        System.out.print("Input length:");
        int length=scn.nextInt();
        System.out.print("Input width:");
        int width=scn.nextInt();
        System.out.println("area="+(length*width));
        scn.close();
    }
}

/* output-------
Input length:5
Input width:3
area=15
--------------*/