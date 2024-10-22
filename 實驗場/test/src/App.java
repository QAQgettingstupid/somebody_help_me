class CCircle {
  private static double pi = 3.14;
  private double radius;

  public CCircle() {
      this(4.5);
  }

  public CCircle(double r) {
    radius = r;
  }

  public void setRadius(double r) {
    radius = r;
    System.out.println("radius=" + radius);
  }
}

class CCoin extends CCircle {
  private int value;

  public CCoin(double r, int v) {
    setRadius(r);
    value = v;
  }
}

public class App {
  public static void main(String args[]) {
    CCoin coin1 = new CCoin(2.5, 10);

  }

}
