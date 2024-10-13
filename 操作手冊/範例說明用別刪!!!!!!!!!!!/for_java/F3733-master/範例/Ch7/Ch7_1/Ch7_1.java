// Ch7_1, 簡單的範例
public class Ch7_1{
    public static void main(String[] args){
        star();  	// 呼叫star() 函數
        System.out.println("Wonderful tonight");
        star();  	// 呼叫star() 函數
    }
 
    public static void star(){  // star() 函數  
        for(int i=0;i<18;i++)
            System.out.print("*");  // 印出18個星號
        System.out.print("\n");    // 換行
    }
}