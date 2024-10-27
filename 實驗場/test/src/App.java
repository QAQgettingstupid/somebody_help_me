class CCircle {
	private double pi = 3.14;
	public double radius;

	void showarea() {
		System.out.println("area=" + pi * radius * radius);
	}
}

public class App {
	public static void main(String args[]) {
		CCircle cir1 = new CCircle();
		System.out.println("radius=" + cir1.radius);
		cir1.showarea();
	}

}
