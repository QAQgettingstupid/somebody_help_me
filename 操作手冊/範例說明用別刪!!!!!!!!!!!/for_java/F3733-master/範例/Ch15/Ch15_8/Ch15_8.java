// Ch15_8, 沒有同步處理的執行緒
class Bank {
    private static int sum = 0;

    public synchronized static void add(int n) { //沒加synchronized中途sleep的時候會被中斷造成數值錯亂
        int tmp = sum;
        tmp = tmp + n; // 累加匯款總額
        try {
            Thread.sleep((int) (1000 * Math.random())); // 小睡0~1秒鐘
        } catch (InterruptedException e) {
        }
        sum = tmp;
        System.out.println("sum= " + sum);
    }
}

class Customer extends Thread { // Customer類別，繼承自Thread類別
    public void run() { // run() 函數
        for (int i = 1; i <= 3; i++)
            Bank.add(100); // 將100元分三次匯入
    }
}

public class Ch15_8 {
    public static void main(String[] args) {
        Customer c1 = new Customer();
        Customer c2 = new Customer();
        c1.start();
        c2.start();
    }
}