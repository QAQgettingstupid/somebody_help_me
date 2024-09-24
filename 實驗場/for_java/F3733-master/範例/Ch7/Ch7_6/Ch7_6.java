// Ch7_6, 傳遞二維陣列
public class Ch7_6{
    public static void main(String[] args){
        int[][] mat={{18,32,65,27,30},{17,56,12,66}};    // 定義二維陣列
        print_mat(mat);     // 將二維陣列mat傳到print_mat()
    }
  
    public static void print_mat(int[][] arr){
        for(int[] row:arr){      // 走訪陣列的內容
            for(int e: row)
                System.out.printf("%3d",e);         // 印出陣列值
            System.out.print("\n");   
        }
    }
}