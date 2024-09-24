// Ch4_7,運算式的型別轉換
public class Ch4_7{
    public static void main(String[] args){
        char ch='m';
        short s=-5;
        int i=6;
        float f=9.7f;
        double d=1.76;    
      
        System.out.print("(s*ch)-(d/f)*(i+f)=");  
        System.out.printf("%7.3f",(s*ch)-(d/f)*(i+f));  // 印出結果
    }
}