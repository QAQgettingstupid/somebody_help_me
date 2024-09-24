// Ch3_13, 由鍵盤輸入資料
import java.util.Scanner;         // 載入Scanner類別
public class Ch3_13{
    public static void main(String[] args){
        Scanner scn=new Scanner(System.in);  // 宣告Scanner類別的物件

        System.out.print("What's your name? ");
        String name=scn.next();     // 輸入字串
        System.out.print("How old are you? ");
        int age=scn.nextInt();      // 輸入整數
        System.out.print(name+",  "+age+" years old.");
        scn.close();                 // 將scn關閉
    }
}