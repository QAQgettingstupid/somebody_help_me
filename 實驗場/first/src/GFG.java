import java.util.Scanner;

public class GFG {
    public static void main(String args[]) {

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter two number: ");

        double a = scanner.nextDouble(), b = scanner.nextDouble();
        double s = a + b;
        String s1 = "GeeksforGeeks";
        scanner.close();

        System.out.println("s = " + s);
        System.out.println("s1 = " + s1);

    }
}
