import java.util.Scanner;
public class Ex5_7{
    public static void main(String[] args){
        Scanner scn=new Scanner(System.in);
        int num,absn;
        System.out.print("請輸入一個整數:");
        num=scn.nextInt();
        System.out.printf("|%d|=",num);
        absn=(num>=0)?num:-num;
        System.out.println(absn);        
        scn.close();
    }
}

/* output----------
請輸入一個整數:-8
|-8|=8
-----------------*/