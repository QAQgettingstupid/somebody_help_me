public class App {
  public static void main(String args[]) {
    int a[] = { 1, 2, 3, 4, 5 };
    add(a);
    for (int i : a)
      System.out.print(i + " ");
  }

  public static void add(int a[]) {

    for (int i = 0; i < a.length; i++)
      a[i] += 10;

    for (int i : a)
      i += 10;
  }
}
