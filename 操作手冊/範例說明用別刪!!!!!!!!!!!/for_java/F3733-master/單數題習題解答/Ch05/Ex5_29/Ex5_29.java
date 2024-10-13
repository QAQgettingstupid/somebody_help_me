public class Ex5_29{
    public static void main(String[] args){
        int i,sum=0;
        for(i=1;i<=100;i++){
            sum+=i*i;
            if(sum>=320)
                break;
        }
        System.out.printf("滿足f(n)<320的最大整數n為%d ",i);
    }
}

/* output------------------
滿足f(n)<320的最大整數n為10 
-------------------------*/