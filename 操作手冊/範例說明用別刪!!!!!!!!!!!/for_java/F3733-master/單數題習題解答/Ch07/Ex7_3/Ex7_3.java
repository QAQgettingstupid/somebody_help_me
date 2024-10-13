public class Ex7_3{
    public static void main(String[] args){
        int result;
        
        result=cubic(5);
        System.out.println("cubic(5)="+result);
    } 

    public static int cubic(int x){
        return x*x*x;            
    }     
}

/* output------
cubic(5)=125
-------------*/