// Ch13_7, 從不同類別內的函數拋出例外
class Test{
    public static void aaa(int a,int b) throws ArithmeticException{   
        int c=a/b;
        System.out.println(a+"/"+b+"="+c);  
    }    
}

public class Ch13_7{
    public static void main(String args[]){  
        try{
            Test.aaa(4,0);
        }
        catch(ArithmeticException e){
            System.out.println(e+" throwed");
        }
    }
}