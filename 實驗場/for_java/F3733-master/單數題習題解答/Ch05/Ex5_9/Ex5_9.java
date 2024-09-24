import java.util.Scanner;
public class Ex5_9{
    public static void main(String[] args){
        Scanner scn=new Scanner(System.in);
        int score;
        System.out.print("請輸入學生成績:");
        score=scn.nextInt();
        if(score>=0){
            if(score>=80 && score<=100)
                System.out.println(score+"分是A級");
            else if(score>=60 && score<=79)
                System.out.println(score+"分是B級"); 
            else if(score>=0 && score<=59)
                System.out.println(score+"分是C級");
        }
        else
            System.out.println("輸入錯誤！");       
        scn.close();
    }
}

/* output------------
請輸入學生成績:98
98分是A級
------------------*/