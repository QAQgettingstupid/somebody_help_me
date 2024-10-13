// Ex15_13
class CData extends Thread{
    private static int sum=30;
    private int n;
    private int sec;
    public CData(int a,int s){
        n=a;
        sec=s;
    }   
    public void run(){     
    while(sum>10)
        sub(n,sec);
    }
    public synchronized static void sub(int a,int s){
        int tmp=sum-a;
        try{
            sleep(s);
        }
        catch(InterruptedException e){}
        if(tmp>0){
            sum=tmp;
            System.out.println("減"+a+"後，餘數為"+sum);
        }
    }
}

public class Ex15_13{
    public static void main(String args[]){
        CData d1=new CData(5,1500);
        CData d2=new CData(9,1000);
        CData d3=new CData(8,2000);
        d1.start();
        d2.start(); 
        d3.start();   
    }
}

/* output--------
減5後，餘數為25
減8後，餘數為17
減9後，餘數為8
減5後，餘數為3
----------------*/

/*
 (a)本題程式的目的在於同步處理。但就Ex15_13來說，宣告了三個執行緒，
 在執行時，這三個緒行緒並沒有共用到sum這個變數，使得sum分別用30減9減9、
 30減5減5、30減8減8，而非30減9，得到的結果再減5，再減8。
 因此這三個執行緒只是共用了程式碼，並沒有共用到資料。

 (b)本題修正錯誤之後，可以發現到，一開始執行時，會等1.5秒才會出現
 執行緒d1的結果；接著再等1秒，會出現執行緒d2的結果；再等2秒，才會出現
 執行緒d3的結果，而不是看哪個執行緒先搶到CPU的資源。
 */