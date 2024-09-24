// Ch5_5, 利用for迴圈計算1加到10的總和
public class Ch5_5{
    public static void main(String[] args){
        int i,sum=0;
       
        for(i=1;i<=10;i++)
            sum+=i;    // 計算sum=sum+i
        System.out.printf("1+2+...+10=%d",sum);  // 印出結果
    }
}