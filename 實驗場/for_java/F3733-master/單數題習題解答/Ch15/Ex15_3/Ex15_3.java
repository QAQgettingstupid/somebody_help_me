// Ex15_3
class Test extends Thread{
    private String id;
    public Test(String str)   {
        id=str;
    }
    public void run(){
        for(int i=1;i<=5;i++){
            for(int j=0;j<100000000;j++);
                System.out.println(id+" "+i);
        }
    }
}

public class Ex15_3{
    public static void main(String args[]){
        Test hi=new Test("Hello");
        Test bye=new Test("Good bye");
        Test morning=new Test("Good morning");
        Test night=new Test("Good night");
        hi.start();
        bye.start();
        morning.start();
        night.start();
    }
}

/* output--------------------
Good night 1
Good night 2  
Good morning 1
Good bye 1    
Good night 3
Good night 4
Good night 5
Hello 1
Good morning 2
Good morning 3
Good bye 2
Good morning 4
Hello 2
Hello 3
Hello 4
Hello 5
Good morning 5
Good bye 3
Good bye 4
Good bye 5
---------------------------*/