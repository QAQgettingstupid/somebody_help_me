import java.util.Random;
import java.util.Scanner;

public class H3_111216019 {
    public static void main(String[] args) {
        System.out.println("作者:蔡芳宇");
        System.out.println("學號:111216019");
        System.out.println("自評:70%+20%+5%");
        System.out.println("特殊功能:第6輪開始,輸入後除了幾A幾B還會提示哪些數字符合A,哪些數字符合B,不加這個試玩覺得有點難猜www");
        System.out.println();
        boolean not_finish = true;
        int chance = 10;

        // Random
        Random rand = new Random();
        int used[] = new int[10];
        int rand_ans[] = new int[4];

        // 將隨機數字放入rand_ans[]
        for (int i = 0; i < 4; i++) {
            int num;

            // 隨機數字並確保數字未重複
            do {
                num = rand.nextInt(10);
            } while (used[num] == 1);

            rand_ans[i] = num;
            used[num]++;
        }

        // 數10次機會
        while (chance-- > 0) {

            int A = 0, B = 0;
            int[] A_rightnum = new int[10];
            int[] B_rightnum = new int[10];
            int[] input = same_num(chance);

            // 判斷幾A幾B,和符合A和B條件的數字
            for (int i = 0; i < 4; i++) {
                if (rand_ans[i] == input[i]) {
                    A_rightnum[input[i]]++;
                    A++;
                } else if (used[input[i]] > 0) {
                    B_rightnum[input[i]]++;
                    B++;
                }
            }
            if (A == 4) {
                System.out.println("you win!!!!!!!");
                not_finish = false;
                break;
            } else {
                System.out.println(A + "A" + B + "B");
                if (chance < 5 && chance > 0) {
                    if (A > 0) {
                        System.out.print("number at right place: ");

                        // 尋找符合A條件的數字,並印出
                        for (int i = 0; i < 10; i++)
                            if (A_rightnum[i] == 1)
                                System.out.print(i + " ");
                        System.out.println();
                    }
                    if (B > 0) {
                        System.out.print("right number but at wrong place: ");

                        // 尋找符合B條件的數字,並印出
                        for (int i = 0; i < 10; i++)
                            if (B_rightnum[i] == 1)
                                System.out.print(i + " ");
                        System.out.println();
                    }
                }
            }
        }
        if (not_finish) {
            System.out.println("you lose");
            System.out.print("the answer is: ");

            // 印出正解
            for (int i = 0; i < 4; i++)
                System.out.print(rand_ans[i]);
        }
    }

    public static int[] same_num(int chance) {
        Scanner scn = new Scanner(System.in);
        boolean check;
        int arr[] = new int[4];

        // 有數字重複時能重新輸入
        do {
            if (chance > 0)
                System.out.println("please enter you answer: (" + (chance + 1) + " chances left)");
            else
                System.out.println("please enter you answer: (last chance)");

            int input = scn.nextInt();
            check = false;
            int[] check_input = new int[10];

            if (input < 1000 || input >= 10000) {
                System.out.println("wrong input,please enter again");
                check = true;
            } else {
                // 檢驗是否有重複數字,同時將輸入轉換成陣列
                for (int i = 3; i >= 0; i--) {
                    arr[i] = input % 10;
                    if (check_input[input % 10] == 1) {
                        System.out.println("wrong input,please enter again");
                        check = true;
                        break;
                    }
                    check_input[input % 10]++;
                    input = input / 10;
                }
            }
        } while (check);
        return arr;
    }
}
