// Ex15_5
class MyPrint implements Runnable{
    private int n;
    private char ch;
    public MyPrint(int a, char c){
        n=a;
        ch=c;
    }
    public void run(){
        for(int i=1;i<=n;i++){
            for(int j=0;j<100000000;j++);
            System.out.print(ch);       
        }
    }
}

public class Ex15_5{
    public static void main(String args[]){
        MyPrint s1=new MyPrint(5,'*');
        MyPrint s2=new MyPrint(3,'$');
        Thread t1=new Thread(s1);
        Thread t2=new Thread(s2);
        t1.start();
        t2.start();
    }
}

/* output----
$$*$****
-----------*/