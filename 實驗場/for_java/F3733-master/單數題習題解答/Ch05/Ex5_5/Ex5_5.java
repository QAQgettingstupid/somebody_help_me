import java.util.Scanner;
public class Ex5_5{
    public static void main(String[] args){
        Scanner scn=new Scanner(System.in);
        char ch;
        System.out.print("請輸入一個字元:");
        ch=scn.next().charAt(0);
        if(ch<='9' && ch>='0')
            System.out.println("此字元是數字");
        if((ch<=90 && ch>=65) || (ch<='z' && ch>='a'))
            System.out.println("此字元是英文字母");
        scn.close();
    }
}

/* output----------
請輸入一個字元:u
此字元是英文字母
----------------*/