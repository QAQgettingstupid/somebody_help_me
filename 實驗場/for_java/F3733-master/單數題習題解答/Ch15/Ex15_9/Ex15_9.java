// Ex15_9
class Wolf implements Runnable{
    public void run(){
        Thread pg=new Thread(new Pig());
        pg.start();
        System.out.println("大野狼對著第三隻小豬的房子吹氣");
        System.out.println("牠不停地吹氣又吹氣");
        System.out.println("還是不能把房子吹倒");
        System.out.println("大野狼非常的生氣");
        System.out.println("牠決定要從煙囪爬進小豬的家裡");
        try{
            pg.join();
        }
        catch(InterruptedException e){
            System.out.println("小豬不在家");
            System.exit(1);
        }          
        try{
            for(int i=1;i<=5;i++){         
                Thread.sleep(300*i);
                System.out.print((i*3)+"分鐘  ");
            }         
        }
        catch(InterruptedException e){
            System.out.println("大野狼不會爬煙囪");
        }    
        System.out.println("\n大野狼爬上煙囪了");
        System.out.println("大野狼從煙囪滑進房子裡");
        System.out.println("就被小豬煮好的水燙死了");
    }
}
class Pig implements Runnable{
    public void run(){
        System.out.println("小豬看到大野狼在爬煙囪");
        System.out.println("就在壁爐上煮了一鍋水");
        try{
            for(int i=1;i<=5;i++){
                Thread.sleep(300*i);
                System.out.print((i*2)+"分鐘  ");
            }
        }
        catch(InterruptedException e){
            System.out.println("鍋子壞了，無法煮水");
        }    
        System.out.println("\n一鍋煮沸的熱水煮好了"); 
    }
 }

public class Ex15_9{
    public static void main(String args[]){
        Thread wf=new Thread(new Wolf());
        wf.start();
    }
}

/* output---------------------------
大野狼對著第三隻小豬的房子吹氣
牠不停地吹氣又吹氣
小豬看到大野狼在爬煙囪
就在壁爐上煮了一鍋水
還是不能把房子吹倒
大野狼非常的生氣
牠決定要從煙囪爬進小豬的家裡
2分鐘  4分鐘  6分鐘  8分鐘  10分鐘
一鍋煮沸的熱水煮好了
3分鐘  6分鐘  9分鐘  12分鐘  15分鐘
大野狼爬上煙囪了
大野狼從煙囪滑進房子裡
就被小豬煮好的水燙死了
-----------------------------------*/