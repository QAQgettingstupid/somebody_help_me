// Ch13_8, 定義自己的例外類別
class CircleException extends Exception { // 定義自己的例外類別
}

class Circle { // 定義類別Circle
    private double radius;

    public void setRadius(double r) /* CircleException/*刪除 */ {
        if (r < 0) {
            try {
                throw new CircleException();
            } catch (CircleException e) {
                System.out.println(" throwed");
            } // 拋出例外
            // 加try catch
        } else
            radius = r;
    }

    public void show() {
        System.out.println("area=" + 3.14 * radius * radius);
    }
}

public class Ch13_8 {
    public static void main(String[] args) {
        Circle c1 = new Circle();
        c1.setRadius(-2.0);
        /*try { // 刪除
            c1.setRadius(-2.0);
        } catch (CircleException e) { // 捕捉由setRadius()拋出的例外
            System.out.println(e + " throwed");
        } // 刪除 */
        c1.show();
    }
}