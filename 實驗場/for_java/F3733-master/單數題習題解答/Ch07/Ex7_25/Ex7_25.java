public class Ex7_25{
    public static void main(String[] args){
        int n=6;
        System.out.println("(a) fib("+n+")="+fib(n));
        System.out.println("(b) fib_rec("+n+")="+fib_rec(n));
        n=50;
        System.out.println("(c) fib("+n+")="+fib(n));
        System.out.println("(c) fib_rec("+n+")="+fib_rec(n));
    }  

    public static long fib(int n){
        long f_1=1;
        long f_2=1;
        long f=0;
        for(int i=3;i<=n;i++){
            f=f_1+f_2;
            f_2=f_1;
            f_1=f;
        }
        return f;     
    }

    public static long fib_rec(int n){        
        if (n==1 || n==2)
           return 1;
        else return fib_rec(n-1)+fib_rec(n-2);
      }
}

/* output------------------------
(a) fib(6)=8
(b) fib_rec(6)=8
(c) fib(50)=12586269025
(c) fib_rec(50)=12586269025
使用遞迴計算費氏數列會非常費時
-------------------------------*/