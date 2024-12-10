// Ch15_4, sleep() 函數的示範
class CTest extends Thread { // 從Thread類別延伸出子類別
    private String id;

    public CTest(String str) { // 建構元，設定成員id
        id = str;
    }

    public void run() { // 改寫Thread類別裡的run() 函數
        for (int i = 0; i < 4; i++) {
            try {
                sleep((int) (1000 * Math.random()));
            } catch (InterruptedException e) {
            }
            System.out.println(id + " is running...");
        }
    }
}

public class Ch15_4 {
    public static void main(String[] args) {
        CTest dog = new CTest("doggy");
        CTest cat = new CTest("kitty");
        dog.start();
        cat.start();
    }
}
