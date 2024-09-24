// Ch5_8, do-while迴圈-累加1至n的程式
import java.util.Scanner;
public class Ch5_8{
    public static void main(String[] args){
        Scanner scn=new Scanner(System.in);
        int n,sum=0;
            
        do{
            System.out.print("請輸入累加的最大值: ");
            n=scn.nextInt();	// 輸入一個整數
        }while(n<1);       	// n要大於等於1,否則會要求重複輸入

        for(int i=1;i<=n;i++)
            sum+=i;       // 計算sum=sum+i
        System.out.printf("1+2+...+%d=%d\n",n,sum);    // 印出結果
        scn.close();
    }
}