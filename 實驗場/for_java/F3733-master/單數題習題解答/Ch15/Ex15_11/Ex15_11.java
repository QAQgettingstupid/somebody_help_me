// Ex15_11
class Animal implements Runnable{
    private String id;
    public Animal(String str){
        id=str;
    }
    public void run(){
        for(int i=1;i<=5;i++){
            try{
                Thread.sleep((int)(100*Math.random()));
            }
            catch(InterruptedException e){}
            System.out.println(id+"來了"+i+"次");
        }
    }    
}

public class Ex15_11{
    public static void main(String args[]){
        Animal Tom=new Animal("狸克");
        Animal Redd=new Animal("狐利");
        Animal Tortimer=new Animal("壽伯");
        Animal Blathers=new Animal("傅達");
        Thread t1=new Thread(Tom);
        Thread t2=new Thread(Redd);
        Thread t3=new Thread(Tortimer);
        Thread t4=new Thread(Blathers);
        t1.start();
        try{
            t1.join();
            t3.start();
            t3.join();
            t4.start();
            t4.join();
            t2.start();
            t2.join();
        }
        catch(InterruptedException e){}
        System.out.println("All Threads are finished");
    }
}

/* output------------------
狸克來了1次
狸克來了2次
狸克來了3次
狸克來了4次
狸克來了5次
壽伯來了1次
壽伯來了2次
壽伯來了3次
壽伯來了4次
壽伯來了5次
傅達來了1次
傅達來了2次
傅達來了3次
傅達來了4次
傅達來了5次
狐利來了1次
狐利來了2次
狐利來了3次
狐利來了4次
狐利來了5次
All Threads are finished
-------------------------*/