// Ch15_2, 啟動執行緒的範例
class CTest extends Thread { // 從Thread類別延伸出子類別CTest
    private String id;

    public CTest(String str) { // 建構元，設定成員id
        id = str;
    }

    public void run() { // 改寫Thread類別裡的run() 函數
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 100000000; j++)
                ; // 空迴圈，用來拖慢10行執行的速度
            System.out.println(id + " is running...");
        }
    }
}

public class Ch15_2 {
    public static void main(String[] args) {
        // 結果並非每次都一樣
        CTest dog = new CTest("doggy");
        CTest cat = new CTest("kitty");
        dog.start(); // 注意是呼叫start(),而不是run()
        cat.start(); // 注意是呼叫start(),而不是run()
    }
}
