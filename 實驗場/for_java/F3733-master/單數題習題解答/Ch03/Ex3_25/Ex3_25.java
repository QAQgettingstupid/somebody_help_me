import java.util.Scanner;
public class Ex3_25{
    public static void main(String[] args){       
        Scanner scn=new Scanner(System.in);

        System.out.print("Input lst Integer:");
        int n1=scn.nextInt();
        System.out.print("Input 2nd Integer:");
        int n2=scn.nextInt();
        System.out.println(n1+"+"+n2+"="+(n1+n2));
        scn.close();       
    }
}

/* output---------------
Input lst Integer:1200
Input 2nd Integer:2100
1200+2100=3300
----------------------*/