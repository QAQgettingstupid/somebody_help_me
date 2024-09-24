// Ch6_1, 一維陣列的使用
public class Ch6_1{
    public static void main(String[] args){  
        int[] a=new int[3];	  // 宣告整數陣列a,並配置可存放3個整數的空間
        a[0]=9;		// 設定第0個元素的值為9
        a[1]=6;		// 設定第1個元素的值為6
       
        for(int i=0; i<a.length; i++) 				
            System.out.printf("a[%d]=%d, ",i,a[i]);	// 印出陣列的內容
        System.out.printf("length=%d",a.length);	// 印出陣列長度
    }
}