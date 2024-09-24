public class Ex4_7{
    public static void main(String[] args){
        int a,b;

        a=10; b=5;
        b*=a;
        System.out.printf("(a) a=%d, b=%d\n",a,b);

        a=10; b=5;
        a/=b++;
        System.out.printf("(b) a=%d, b=%d\n",a,b);

        a=10; b=5;
        a/=++b;
        System.out.printf("(c) a=%d, b=%d\n",a,b);
        
        a=10; b=5;
        a%=--b;
        System.out.printf("(d) a=%d, b=%d\n",a,b);
        
        a=10; b=5;
        b%=a++;
        System.out.printf("(e) a=%d, b=%d\n",a,b);
    }
}

/* output--------
(a) a=10, b=50
(b) a=2, b=6
(c) a=1, b=6
(d) a=2, b=4
(e) a=11, b=5
--------------*/