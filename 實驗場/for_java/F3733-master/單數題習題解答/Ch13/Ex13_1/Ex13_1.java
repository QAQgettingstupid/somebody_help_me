// Ex13_1, 例外訊息的擷取
public class Ex13_1{
    public static void main(String[] args){
        int num=12,den=0;
        int ans=num/den;
        System.out.println("end of main()!!");
    }
} 

/* output------------------------------------------------------------
Exception in thread "main" java.lang.ArithmeticException: / by zero
        at Ex13_1.main(Ex13_1.java:5)
-------------------------------------------------------------------*/