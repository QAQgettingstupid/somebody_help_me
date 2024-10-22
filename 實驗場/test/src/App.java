

public class App {
  public static void main(String args[]) {
    int a=100,b=14;
    expre(a, b, '-');

  }
  public static void expre(int a, int b, char oper){
		switch (oper)	{
			case '+':
				System.out.println(a+"+"+b+"="+(a+b));
				break;
			case '-':
				System.out.println(a+"-"+b+"="+(a-b));
			case '*':
				System.out.println(a+"*"+b+"="+(a*b));				
			case '/':
				System.out.println(a+"/"+b+"="+(a/b));
			default:
				System.out.println("Unknown expression!!");
		}
    }
}


