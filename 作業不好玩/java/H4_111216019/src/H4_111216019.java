import java.util.Scanner;

//作者:蔡芳宇
//學號:111216019
//自評:20%+80%

public class H4_111216019 {

    // doomsday公式-> (2 + 5*(y/4) + 4*(y%100) + 6*(y%400)%7, y=當前年分
    // mod(7) = 0->星期天
    // mod(7) = 1~6 ->星期一~六
    public static void main(String[] args) throws Exception {

        Scanner scn = new Scanner(System.in);
        System.out.println("please enter year/month/date :  ex.(2024/11/18)");
        while (scn.hasNext()) {

            String input = scn.nextLine();
            int month_day[][] = { { 0, 3, 28, 14, 4, 9, 6, 11, 8, 5, 10, 7, 12 },
                    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };

            // 輸入切割
            String[] parts = input.split("/");
            int year = Integer.parseInt(parts[0]), month = Integer.parseInt(parts[1]);

            // 閏年判斷
            if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
                if (month == 1)
                    month_day[0][1]++;
                else if (month == 2) {
                    month_day[0][2]++;
                    month_day[1][2]++;
                }
            }

            int doomsday = (2 + (year % 4) * 5 + (year % 100) * 4 + (year % 400) * 6) % 7;

            // first line
            int now_print = 1;
            int first_day = doomsday - (month_day[0][month] - 1) % 7;
            if (first_day < 0)
                first_day += 7;
            int space = (first_day >= 2) ? 3 * first_day : 0;

            // 一個國字3格數字位
            System.out.println("日 " + "一 " + "二 " + "三 " + "四 " + "五 " + "六");

            // 空格輸出
            for (int i = 0; i < space; i++)
                System.out.print(" ");

            // 第一個禮拜
            while (first_day < 7) {
                System.out.printf("%-3d", now_print);
                now_print++;
                first_day++;
            }

            // 第一個禮拜以後
            for (; now_print <= month_day[1][month]; now_print++) {
                if (first_day == 7) {
                    System.out.println();
                    first_day = 0;
                }
                System.out.printf("%-3d", now_print);
                first_day++;
            }
            System.out.println();
            System.out.println("please enter year/month/date :  ex.(2024/11/18)");
        }
    }
}
