public class Ex7_27{
    public static void main(String[] args){
        int n=100;
        System.out.println("sum("+n+")="+sum(n));
    }  

    public static int sum(int n){
        if (n==1)
            return 1;
        else
            return n+sum(n-1);
    }
}

/* output-------
sum(100)=5050
--------------*/