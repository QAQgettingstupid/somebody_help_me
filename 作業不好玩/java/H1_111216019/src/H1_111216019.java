import java.util.Scanner;
import java.lang.Math;

public class H1_111216019 {
    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);
        int num;
        while (scn.hasNext()) {
            num = scn.nextInt();
            for (int i = 2; i < Math.sqrt(num); i++) {
                int power = 0;
                while (num % i == 0) {
                    num /= i;
                    power++;
                }
                if (power > 0) {

                }
            }
        }
    }
}
