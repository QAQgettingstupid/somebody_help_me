// Ex12_19
public class Ex12_19{
    public static void main(String args[]){
        System.out.println("f(5)="+f(5));
    }
    public static double f(int n){
        double sum=0.0;
        for(int i=1;i<=n;i++)
            sum+=Math.sqrt(i);
        return sum;
    }  
}

/* output---------------
f(5)=8.382332347441762
----------------------*/