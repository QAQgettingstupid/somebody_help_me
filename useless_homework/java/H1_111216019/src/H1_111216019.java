import java.util.Scanner;
import java.lang.Math;

public class H1_111216019 {
    public static void main(String[] args) {

        System.out.println("作者:蔡芳宇");
        System.out.println("學號:111216019");
        System.out.println("自評:70%+20%+10% ,如果沒遇到我意料之外錯誤的話,拜託別用long去測我上限就只設int");
        System.out.println("please enter a number:");
        Scanner scn = new Scanner(System.in);
        int num;
        while (scn.hasNext()) {
            num = scn.nextInt();
            boolean first = true, is_prime = true;

            if (num == 1)
                System.out.printf("is not prime\n");

            else {
                System.out.printf("%d = ", num);

                // 質因數分解
                for (int i = 2; i <= Math.sqrt(num); i++) {

                    if (num == 1)
                        break;

                    int power = 0;

                    // 算為幾次方
                    while (num % i == 0) {
                        num /= i;
                        power++;
                    }
                    if (power > 0) {
                        is_prime = false;
                        if (first)
                            System.out.printf("%d^%d ", i, power);
                        else
                            System.out.printf("* %d^%d", i, power);
                    }
                }
                if (is_prime) {
                    System.out.printf("%d^1\n", num);
                    System.out.printf("is prime\n");
                } else {
                    System.out.printf("* %d^1\n", num);
                    System.out.printf("is not prime\n");
                }
            }

            System.out.println("please enter a number:");
        }
        scn.close();
    }
}
