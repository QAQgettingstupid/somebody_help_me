// Ch6_3, 比較陣列元素值的大小
public class Ch6_3{
    public static void main(String[] args){ 
        int arr[]={17,48,30,74,62};  // 宣告整數陣列a,並設定初值
        int max=arr[0];    // 將max設值為陣列的第0個元素

        for(int i:arr){ 
            if(i>max) 
                max=i;    // 將max設值為目前找到的最大值
        }
        System.out.printf("Maximum is %d",max);  // 印出最大值
    }
}