// Ch6_4, 二維陣列的存取範例
public class Ch6_4 {
    public static void main(String[] args) {

        /*
         * int[] a = { 0, 1, 5, 4 };
         * 
         * for (int temp : a)
         * System.out.print(temp + " ");
         */

        int[][] a = { { 32, 35, 26, 30 }, { 34, 30, 33, 31 } };

        for (int[] r : a)
            for (int c : r)
                System.out.print(c + " ");

    }
}