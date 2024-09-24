// Ch13_6, 指定函數拋出例外
public class Ch13_6{
    public static void aaa(int a,int b) throws ArithmeticException{
        int c;
        c=a/b;
        System.out.println(a+"/"+b+"="+c);      
    }
      
    public static void main(String args[]){  
        try{
            aaa(4,0);
        }
        catch(ArithmeticException e){
            System.out.println(e+" throwed");
        }
    }
}  