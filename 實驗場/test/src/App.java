interface InnerApp {
    public final int num = 5;

    abstract void print();
}

public class App implements InnerApp {
    public static void main(String[] args) throws Exception {
        App a = new App();
        a.print();
    }

    public void print() {
        System.out.println("num= " + num);
    }
}
