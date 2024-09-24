//Ch3_2,有錯誤的範例
public class Ch3_2{
    public static void main(String[] args){
        byte num=-360;		   // 錯誤，byte容許的最小值為-128 
        short area=40000;		   // 錯誤，short容許的最大值為32767
        int value=600L; 		   // 錯誤，600L是長整數
        long width=12345678900;  // 錯誤，12345678900後面要加L
      
        System.out.println(num+" is of type byte");
        System.out.println(area+" is of type short");
        System.out.println(value+" is of type int");
        System.out.println(width+" is of type long");
    }
}