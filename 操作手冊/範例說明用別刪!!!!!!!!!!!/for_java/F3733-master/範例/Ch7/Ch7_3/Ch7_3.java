// Ch7_3, 計算長方形的面積
public class Ch7_3{
    public static void main(String[] args){
        int rec_area;
        rec_area=area(8,4);  // 傳入8與4兩個引數到area()裡
        System.out.println("area= "+rec_area);
    }
  
    public static int area(int width, int height){
        return width*height;  // 傳回長方形面積
    }
}
