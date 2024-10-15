// Ch7_5, 簡單的範例
public class Ch7_5 {
    public static void main(String[] args) {
        int[] score = { 9, 14, 6, 18, 2, 10 }; // 宣告一維陣列score
        largest(score); // 將一維陣列score傳入largest() 函數

        int max = score[0];
        for (int i = 0; i < score.length; i++)// 找尋最大值
            if (max < score[i])
                max = score[i];
        System.out.println("largest num = " + max);
    }

    public static void largest(int[] arr) { // 利用arr接收傳進來的陣列
        int max = arr[0];
        for (int i = 0; i < arr.length; i++) { // 找尋最大值
            arr[i]++;
            if (max < arr[i])
                max = arr[i];
        }
        System.out.println("largest num = " + max);
    }
}