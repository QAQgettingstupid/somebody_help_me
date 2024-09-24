public class Ex5_19{
    public static void main(String[] args){
        int num=1, sum=0;
        for(int i=1;i<=50;i++){
            num=i*i;
            if(i%2==0)
                sum-=num;            
            else
                sum+=num;           
        }
        System.out.println("1^2-2^2+3^2-4^2+...+49^2-50^2="+sum);
    }
}

/* output-----------------------------
1^2-2^2+3^2-4^2+...+49^2-50^2=-1275
------------------------------------*/