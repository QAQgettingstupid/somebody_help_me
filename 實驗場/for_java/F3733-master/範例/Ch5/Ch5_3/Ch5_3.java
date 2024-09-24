// Ch5_3, 條件運算子?:的使用-找出較大的數
public class Ch5_3{
    public static void main(String[] args){
        int a=8,b=3,max;
       
        max=(a>b)?a:b;			// a>b時,max=a,否則max=b
        System.out.printf("a=%d, b=%d, %d是較大的數\n",a,b,max);
    }
}