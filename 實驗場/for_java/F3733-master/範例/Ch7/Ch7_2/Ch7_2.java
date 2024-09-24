// Ch7_2, 計算1+2+..+end 的平均
public class Ch7_2{
    public static void main(String[] args){
        double avg=average(4);               // 呼叫average()函數
        System.out.printf("avg=%6.2f",avg);
    }
   
    public static double average(int end){  // 定義average()函數
        int sum=0;
        double avg;
        for(int i=1;i<=end;i++)
           sum+=i;
        avg=(double)sum/end;
        return avg;               // 傳回平均，其型別為double
    }
} 
