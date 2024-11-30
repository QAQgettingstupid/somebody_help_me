import java.util.InputMismatchException;
import java.util.Scanner;

//作者:蔡芳宇
//學號:111216019
//自評:20%+60%+20%

class is_q extends Exception {

}

public class H6_111216019 {

    public static void main(String[] args) throws InputMismatchException {
        Scanner scn = new Scanner(System.in);
        int total = 0, num;
        System.out.println("please enter a number: (enter 'q' to see total)");

        //重複輸入
        while (scn.hasNext()) {
            try {
                num = scn.nextInt();
                total += num;
            } catch (InputMismatchException e) {
                String s = scn.next();
                if (s.equals("q")) {
                    try {
                        throw new is_q();
                    } catch (is_q e_) {
                        System.out.println("total= " + total);
                    }
                } else
                    System.out.println("input should be intger or 'q' only!!!!!");
            }
            System.out.println();
            System.out.println("please enter a number: (enter 'q' to see total)");
        }
    }
}
