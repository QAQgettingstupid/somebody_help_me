// Ch3_6, 型別的溢位處理
public class Ch3_6{
    public static void main(String[] args){
        int i=Integer.MAX_VALUE;    	// 將i設為int型別的最大值

        System.out.println("i="+i);
        System.out.println("i="+(i+1));         	// 會發生溢位
        System.out.println("i+1="+(i+1L));      	// 自動型別轉換 
        System.out.println("i+2="+((long)i+2));	// 強制型別轉換
    }
}