public class Ex7_9{
    public static void main(String[] args){
        int num=17;
        if(is_prime(num))
            System.out.printf("%d是質數\n",num);
        else    
            System.out.printf("%d不是質數\n",num);                                
        }  

    public static boolean is_prime(int n){
        boolean p_flag=true;            // 預設為質數
        if (n>0){
            int k=(int)Math.sqrt(n);    // k為n的正平方根，取整數
            for(int i=2;i<=k;i++){
                if(n%i==0){
                    p_flag=false;       // 不是質數
                break;
                }
            }
        }
        return p_flag;     
    }     
}

/* output----
17是質數 
-----------*/