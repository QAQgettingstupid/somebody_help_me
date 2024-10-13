public class Ex7_15{
    public static void main(String[] args){             
        System.out.println("min(5,8)="+min(5,8));                             
    }  

    public static int min(int a,int b){
        if(a<b)
            return a;
        else
            return b;
    }     
}

/* output----
min(5,8)=5
-----------*/