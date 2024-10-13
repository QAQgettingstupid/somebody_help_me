import java.util.Scanner;
public class Ex5_21{
    public static void main(String[] args){
        Scanner scn=new Scanner(System.in);
        int n,cnt=0;
        System.out.print("請輸入一個整數:");
        n=scn.nextInt();   
        while((n/=10)!=0)
            cnt++;
        System.out.println((cnt+1)+"個位數的整數");
        scn.close();
    }
}

/* output--------------
請輸入一個整數:23983
5個位數的整數
---------------------*/