// Ch4_3, 遞增運算子「++」
public class Ch4_3{
    public static void main(String[] args){
        int a=5,b=5;
 
        System.out.printf("++a的傳回值: %d\n",++a);  //遞增運算子在前
        System.out.printf("執行完++a之後，a= %d\n",a);
        System.out.printf("b++的傳回值: %d\n",b++); 	//遞增運算子在後
        System.out.printf("執行完b++之後，b= %d\n",b);
    }
}