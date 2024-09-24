// Ch3_10, 列印跳脫序列
public class Ch3_10{
    public static void main(String[] args){
        char ch1='\042';    	// 雙引號字元的八進位碼為042
        char ch2='\u0022';  	// 雙引號字元的十六進位碼為0022

        System.out.println("\"Time is money!\"");
        System.out.println(ch1+"Time flies."+ch1);
        System.out.println(ch2+"Tomorrow never comes"+ch2);
    }
}