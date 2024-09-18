import java.util.Scanner;

public class test {

    public void Add(double a, double b) {
        System.out.println("ans = " + (a + b));
    }
    
    
    public static void add(double a, double b) {
        System.out.println("ans = " + (a + b));
    }

    public static void main(String args[]) {

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter two number: ");

        double a = scanner.nextDouble(), b = scanner.nextDouble();
        scanner.close();
        test first = new test();
        first.Add(a, b);
        test.add(a, b);

        String s1 = "GeeksforGeeks";
        System.out.println("s1 = " + s1);

    }
}
