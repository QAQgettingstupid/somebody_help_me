public class Ex5_17{
    public static void main(String[] args){
        int num=64;
        System.out.print(num+"的因數有");        
        for(int i=1;i<=num;i++){
            if(num%i==0)
                System.out.printf("%d ",i);     
        }
    }
}

/* output-------------------
64的因數有1 2 4 8 16 32 64
--------------------------*/