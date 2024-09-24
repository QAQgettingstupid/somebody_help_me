// Ch3_9, 字元型別的範例
public class Ch3_9{
    public static void main(String[] args){
        char c1='G';    	// 將字面值'G'設定給c1存放
        char c2=71;   		// 利用Unicode設定c2為字元'G'
        char c3='\u0047'; 	// 利用16進位的Unicode設定c3為字元'G'
        int uni='好';      	// 取得 '好' 字的Unicode

        System.out.println("c1="+c1+", c2="+c2+" ,c3="+c3);
        System.out.println("uni="+uni);
        System.out.println((int)'好');  // 印出字元的Uincode
    }
}