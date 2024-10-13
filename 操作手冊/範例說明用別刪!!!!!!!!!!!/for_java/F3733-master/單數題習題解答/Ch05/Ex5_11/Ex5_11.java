import java.util.Scanner;
public class Ex5_11{
    public static void main(String[] args){
        Scanner scn=new Scanner(System.in);
        int day;
        System.out.print("請輸入1-7之間的數:");
        day=scn.nextInt();
        switch(day){
            case 1: case 2: case 3: case 4: case 5:
                System.out.println("今天要上班上課");
                break;
            case 6:
            case 7:
                System.out.println("今天休息");
                break;
            default:
                System.out.println("輸入錯誤");
        }
        scn.close();
    }
}

/* output-------------
請輸入1-7之間的數:5
今天要上班上課
--------------------*/