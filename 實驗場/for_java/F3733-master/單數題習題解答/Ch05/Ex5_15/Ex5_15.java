public class Ex5_15{
    public static void main(String[] args){
        int sum=0;
        System.out.print("1~100內所有整數的平方和:");        
        for(int i=1;i<=100;i++)
            sum+=i*i;            
        System.out.println(sum);                
    }
}

/* output-----------------------
1~100內所有整數的平方和:338350
------------------------------*/