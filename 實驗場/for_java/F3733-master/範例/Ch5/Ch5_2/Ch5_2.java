// Ch5_2, if-else敘述的練習-判別奇偶數
public class Ch5_2{
    public static void main(String[] args){
        int a=15; 
        if (a%2==0)  	// 如果可被2整除
            System.out.printf("%d is an even number",a); // 印出a為偶數
        else
            System.out.printf("%d is an odd number",a);  // 印出a為奇數
    }
}