public class Ex6_9{
    public static void main(String[] args){       
        int count=0, i, indx=0;   
        int[] primes=new int[10];
            
        for(int n=1;count<10;n++){
            for(i=2;n%i != 0;i++);
                if(i==n){
                    primes[indx++]=n;                    
                    count++;
                }
        }
        System.out.print("primes[]元素: ");
        for(int j=0;j<primes.length;j++)
            System.out.printf("%d ",primes[j]);                
    }  
}

/* output--------------------------------
primes[]元素: 2 3 5 7 11 13 17 19 23 29 
---------------------------------------*/