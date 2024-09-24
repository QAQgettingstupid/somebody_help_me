// Ch7_4, 函數傳值的範例
public class Ch7_4{
    public static void main(String[] args){
        int num=8;
        add10(num);  		// 呼叫add10(),並傳遞num
        System.out.printf("in main(), num = %d\n",num);
    }
  
    public static void add10(int num){
        num=num+10;		    // 將num的值加10之後，設回給num
        System.out.printf("in add10(), num= %d\n",num);     
    }
}