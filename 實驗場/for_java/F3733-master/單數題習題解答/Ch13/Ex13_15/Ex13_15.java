// Ex13_15
class IllArgException extends Exception{}
class NotOddException extends Exception{}
public class Ex13_15
{
   public static void main(String args[]){
        int n=-11;
        try{
            if(n<=0)
                throw new IllArgException();
            if(n%2==0)
                throw new NotOddException();   
            odd(n);
        }
        catch(IllArgException e){
           System.out.println("n值小於等於0, 無法處理");
        }
        catch(NotOddException e){
           System.out.println("n值為偶數, 無法處理");
        }
    }
    public static void odd(int n) throws IllArgException,NotOddException{      
        for(int i=1;i<=n;i+=2)
           System.out.print(i+" ");
        System.out.println();     
    }
}

/* output-------------
n值小於等於0, 無法處理
--------------------*/