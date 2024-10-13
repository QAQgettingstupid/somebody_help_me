// Ex13_19
import java.io.*;
class ArgumentOutOfBound extends Exception{}
public class Ex13_19{
    public static void main(String args[])throws IOException{
        int n;
        BufferedReader buf;
        String str;
        buf=new BufferedReader(new InputStreamReader(System.in));        
        try{
            System.out.print("Input an integer:");
            str=buf.readLine();
            n=Integer.parseInt(str);
            if(n<=1)
                throw new ArgumentOutOfBound();
            if(prime(n))
                System.out.println(n+" is a prime");
            else
                System.out.println(n+" is not a prime");
            }
            catch(ArgumentOutOfBound e){
                System.out.println("Argument Out Of Bound!!");
            }   
        }
        public static boolean prime(int num){
           int div=2;
           boolean isprime=true;
           
           while(div*div <=num){
              if(num%div == 0){
                 isprime=false;
                 break;
              }
              div++;
           }
           return isprime;
        }
         
}

/* output----------------
Input an integer:23
23 is a prime
-----------------------*/