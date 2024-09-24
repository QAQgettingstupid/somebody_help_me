public class Ex7_7{
    public static void main(String[] args){        
        for(int i=1;i<=100;i++){            
            if(is_even(i)){
                if(i%9==0)
                    System.out.print(i+" ");  
            }                          
        }        
    } 

    public static boolean is_even(int n){
        if(n%2==0)
            return true;
        else return false;            
    }     
}

/* output-------
18 36 54 72 90 
--------------*/