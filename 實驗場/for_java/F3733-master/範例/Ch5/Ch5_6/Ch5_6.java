// Ch5_6, for迴圈裡的區域變數
public class Ch5_6 {
    public static void main(String[] args) {

        for (int i = 1; i <= 10; i++) { // 在迴圈內宣告變數i
            int b = (i % 2 == 0) ? 1 : 0;
            if (b == 1)
                System.out.printf("even\n");
            else
                System.out.printf("odd\n");
        }

    }
}