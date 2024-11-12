public class App {
    public static void main(String[] args) throws Exception {
        String a = "abc";
        String b = new String("abc");
        String c = new String("abc");
        String d = "abc";
        System.out.println(a == b);
        System.out.println(b == c);
        System.out.println(c == d);
        System.out.println(a == d);
    }
}
