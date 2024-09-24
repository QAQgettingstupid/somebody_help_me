// Ch4_6,位元運算子
public class Ch4_6{
    public static void main(String[] args){
        int a=7, b=13;
        System.out.printf("%d & %d = %d\n",a, b, a&b);	// 位元AND
        System.out.printf("%d | %d = %d\n",a, b, a|b);	// 位元OR
        System.out.printf("!%d = %d\n",a, ~a);   		// 位元NOT
        System.out.printf("%d ^ %d = %d\n",a, b, a^b);	// 位元XOR
        System.out.printf("%d >> 2 = %d\n",a, a>>2);		// 右移兩個位元
        System.out.printf("%d << 2 = %d\n",a, a<<2);		// 左移兩個位元
    }
}