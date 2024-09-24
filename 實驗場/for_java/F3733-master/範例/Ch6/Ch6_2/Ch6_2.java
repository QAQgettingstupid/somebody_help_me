// Ch6_2, 設定陣列初值並計算平均
public class Ch6_2{
    public static void main(String[] args){ 
        int sum=0;
        int[] a={62,7,12,3,8,47};		// 宣告整數陣列a並設定初值
      
        for(int i=0;i<a.length;i++)	// 計算陣列元素的和
            sum+=a[i];
        System.out.printf("Average = %5.2f",(float)sum/a.length);
    }
}