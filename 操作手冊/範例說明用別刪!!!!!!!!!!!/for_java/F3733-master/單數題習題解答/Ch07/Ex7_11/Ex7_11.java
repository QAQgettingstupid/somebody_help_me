public class Ex7_11{
    public static void main(String[] args){             
        System.out.println("gcd(12,16)="+gcd(12,16));                             
    }  

    public static int gcd(int m, int n){
        while(m%n!=0){
            int temp=m%n;
            m=n;
            n=temp;
        }
        return n;
    }     
}

/* output------
gcd(12,16)=4
-------------*/