import java.util.Scanner;
public class Ex3_23{
    public static void main(String[] args){       
        Scanner scn=new Scanner(System.in);

        System.out.print("Input a String:");
        String str=scn.nextLine();
        System.out.println("Output："+str);
        scn.close();       
    }
}

/* output--------------------------------------
Input a String:"Wrong never comes right!!"
Output："Wrong never comes right!!"
---------------------------------------------*/