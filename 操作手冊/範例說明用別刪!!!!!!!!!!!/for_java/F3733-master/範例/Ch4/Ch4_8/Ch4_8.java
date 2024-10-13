// Ch4_8, 強制型別轉換
public class Ch4_8 {
    public static void main(String[] args) {
        int a = 120;
        int d = 5;
        byte c = 120;
        float b = 10;

        System.out.printf("(byte)a/b=%6.3f\n", (byte) a / b);
        // System.out.printf("a= " + a + " a= " + (byte) a); // 印出a、b的值
        /*
         * System.out.printf("a/b=%d\n",a/b); // 印出a/b的值
         * System.out.printf("(float)a/b=%6.3f\n",(float)a/b);
         */
    }
}