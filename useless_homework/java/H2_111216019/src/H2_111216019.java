import java.util.Scanner;

public class H2_111216019 {
    public static void main(String[] args) {
        System.out.println("作者:蔡芳宇");
        System.out.println("學號:111216019");
        System.out.println("自評:70%+20%+10% ,如果沒遇到我意料之外錯誤的話,我努力把他從c++修過來了www");
        System.out.println();
        System.out.println("please enter numbers for sorting:");
        Scanner scn = new Scanner(System.in);
        String input;
        boolean flag;
        while (scn.hasNext()) {
            input = scn.nextLine();
            flag = true;

            // 檢查是否為整數
            for (int i = 0; i < input.length(); i++)
                if ((input.charAt(i) > '9' || input.charAt(i) < '0') && input.charAt(i) != '-'
                        && input.charAt(i) != ' ') {

                    System.out.println("not integer,please enter again:");
                    flag = false;
                    break;
                }

            if (flag) {

                // 字串以" "分割
                String[] parts = input.split(" ");

                int num[] = new int[parts.length];

                // 切割後字串轉int放入陣列
                for (int i = 0; i < parts.length; i++)
                    num[i] = Integer.parseInt(parts[i]);

                // 排序
                for (int i = 0; i < num.length; i++) {
                    int max = num[i], temp_index = i;

                    // 找最大
                    for (int j = i + 1; j < num.length; j++) {
                        if (num[j] > max) {
                            max = num[j];
                            temp_index = j;
                        }
                    }
                    System.out.println("test line=" + max);
                    int temp = num[i];
                    num[i] = max;
                    num[temp_index] = temp;

                }

                // 輸出結果
                for (int i = 0; i < num.length; i++) {
                    if (i == num.length - 1)
                        System.out.println(num[i]);
                    else
                        System.out.print(num[i] + " ");
                }
            }
            System.out.println("please enter numbers for sorting:");
        }
        scn.close();
    }
}
