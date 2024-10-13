// Ch13_9, 捕捉InputMismatchException例外
import java.util.*;
public class Ch13_9{
    public static void main(String[] args){
        int num;
        Scanner scn=new Scanner(System.in);
        try{
            System.out.print("請輸入一個整數: ");   // 輸入整數
            num=scn.nextInt();
            System.out.println("num="+num);
        }
        catch(Exception e){						      // 捕捉所有的例外
            System.out.println("拋出"+e+"例外");	  // 印出例外的種類
        }        
        scn.close();
    }
}