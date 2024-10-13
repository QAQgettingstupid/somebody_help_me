public class Ex3_21{
    public static void main(String[] args){       
        float b=12.3456f;

        System.out.printf("(a) b=%0+8.2f\n",b);
        System.out.printf("(b) b=%+9.6f\n",b);
        System.out.printf("(c) b=%8.3f\n",b);
        System.out.printf("(d) b=%8.0f\n",b);
        System.out.printf("(e) b=%7.2f\n",b);       
        System.out.printf("(f) b=%08.3f\n",b);              
    }
}

/* output----------
(a) b=+0012.35
(b) b=+12.345600
(c) b=  12.346
(d) b=      12
(e) b=  12.35
(f) b=0012.346
----------------*/