// Ex13_17
import java.util.Scanner;
class IntegerlessThanZero extends Exception{}
class IntegerGreatetThanZero extends Exception{}
class IntegerEqualToZero extends Exception{}
public class Ex13_17{
    public static void main(String args[]){
        Scanner scn=new Scanner(System.in);
        System.out.print("請輸入一個整數: ");        
        int num=scn.nextInt();
        scn.close();
        try{ 
            if(num<0)
                throw new IntegerlessThanZero();              
            else if(num>0)
                throw new IntegerGreatetThanZero();
            else if(num==0)
                throw new IntegerEqualToZero();
        }
        catch(IntegerlessThanZero e){
            System.out.println("您輸入的整數的值小於0");
        }
        catch(IntegerGreatetThanZero e){
            System.out.println("您輸入的整數的值大於0");
        }
        catch(IntegerEqualToZero e){
            System.out.println("您輸入的整數的值等於0");
        }
    }
}

/* output----------------
請輸入一個整數: -7
您輸入的整數的值小於0
-----------------------*/