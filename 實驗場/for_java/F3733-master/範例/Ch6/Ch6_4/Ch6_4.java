// Ch6_4, 二維陣列的存取範例
public class Ch6_4{
    public static void main(String[] args){ 
        int sum=0;
        int[][] sales={{32,35,26,30},{34,30,33,31}}; // 宣告陣列並設定初值
 
        for(int[] r:sales){ 
            for(int c:r){
                sum+=c;		// 加總銷售量
            }
        }
        System.out.printf("總銷售量為 %d 部車",sum);
    }
}