import java.util.Scanner;
public class Ex5_13{
    public static void main(String[] args){
        Scanner scn=new Scanner(System.in);
        char ch;
        System.out.print("請輸入動物名稱:");
        ch=scn.next().charAt(0);
        switch(ch){
            case '貓':
                System.out.println("喵喵叫");
                break;
            case '狗':
                System.out.println("汪汪叫");
                break;
            case '羊':
                System.out.println("咩咩叫");
                break;            
            default:
                System.out.println("不明動物");
        }
        scn.close();
    }
}

/* output---------------
請輸入一個中文字元:貓
喵喵叫
----------------------*/