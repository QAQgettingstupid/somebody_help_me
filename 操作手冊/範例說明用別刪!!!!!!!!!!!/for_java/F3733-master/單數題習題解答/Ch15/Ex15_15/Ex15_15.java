// Ex15_15
class  Prime extends Thread{
    private String id;
    private long start;
    private long end;
    public long count=0;
    public Prime(String str,long a,long b){
        id=str;
        if(a>=2)
            start=a;
        else
            start=2L;
        end=b;
    }
    public synchronized void prime(){
        for(long m=start;m<=end-1;m++)
            for(long n=2L;n<=m;n++){
            if(m%n==0 && n!=m)
                break;
            else if(n==m)
                count++;
            }
    }
   public void run(){
        prime();
        System.out.println(id+" 的質數有 "+count+" 個");
    }
}
public class Ex15_15{
    public static void main(String args[]){
        Prime p1=new Prime("2~100000",2,100000);
        Prime p2=new Prime("100000~200000",100001,200000);

        p1.start();
        p2.start();
    }
}

/* output-----------------------
2~100000 的質數有 9592 個
100001~200000 的質數有 8392 個
------------------------------*/
