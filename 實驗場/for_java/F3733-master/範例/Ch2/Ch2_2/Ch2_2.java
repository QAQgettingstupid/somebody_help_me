// Ch2_2, 變數的宣告
public class Ch2_2{     // 定義類別Ch2_2
    public static void main(String[] args){  
        int a;			// 宣告變數a，但不設定初值
        int b=4, sum; 	// 宣告b和sum兩個變數，但只將b的值設為4
      
        a=5;			// 設定a的值為5
        sum=a+b;		// 將sum的值設為a+b
        System.out.println("sum= "+sum);  // 印出sum的值
    }
}