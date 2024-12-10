// Ch15_7, 執行緒的優先順序
class CTest extends Thread { // 從Thread類別延伸出子類別
    private String id;

    public CTest(String str) { // 建構元，設定成員id
        id = str;
    }

    public void run() { // 改寫Thread類別裡的run()
        for (int i = 0; i < 3; i++) {
            try {
                sleep(1000); // 小睡1秒
            } catch (InterruptedException e) {
            }
            System.out.println(id + " is running...Priority = " + this.getPriority()); // 印出哪個執行緒被執行，並取得優先權值
        }
    }
}

public class Ch15_7 {
    public static void main(String[] args) {
        CTest dog = new CTest("doggy");
        CTest cat = new CTest("kitty");
        CTest rabbit = new CTest("rabbit");
        CTest sheep = new CTest("sheep");
        CTest horse = new CTest("horse");

        cat.setPriority(Thread.MAX_PRIORITY); // 設定執行序的優先權
        dog.setPriority(Thread.MIN_PRIORITY);
        rabbit.setPriority(7);
        horse.setPriority(3);

        dog.start(); // 啟動執行緒
        cat.start();
        rabbit.start();
        sheep.start();
        horse.start();
    }
}
