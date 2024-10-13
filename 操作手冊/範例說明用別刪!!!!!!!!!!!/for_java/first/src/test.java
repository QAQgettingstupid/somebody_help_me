import java.util.Scanner;

class parent {

    public void show(){
        System.out.println("from parent\n");  
    }
}

class child extends parent{

    public void show(){
        System.out.println("from child\n");  
    }
}

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

        parent test1 = new parent();
        parent test2 = new child();

        test1.show();
        test2.show();
    }
}
