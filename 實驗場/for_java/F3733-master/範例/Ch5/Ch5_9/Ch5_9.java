// Ch5_9, 巢狀for迴圈求9*9乘法表
public class Ch5_9{
    public static void main(String[] args){
        for (int i=1;i<=3;i++){		// 外層迴圈      
            for (int j=1;j<=4;j++)	// 內層迴圈
                System.out.printf("%d*%d=%2d   ",i,j,i*j);
            System.out.println();   // 換行
        }
    }
}