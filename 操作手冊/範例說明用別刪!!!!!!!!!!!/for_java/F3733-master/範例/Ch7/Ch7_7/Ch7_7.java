// Ch7_7, 傳回一維陣列的函數
public class Ch7_7 {
    public static void main(String[] args) {
        int[] a1 = { 18, 32, 65, 27, 30 }; // 宣告一維陣列a1並設定初值
        int[] a2; // 宣告一維陣列a2
        a2 = add10(a1); // 呼叫add10()，並把傳回的值設給陣列a2
        for (int e : a2){ // 印出陣列的內容
            System.out.printf("%3d", e);
        }
        System.out.println();
        for (int i : a1)
            System.out.printf("%3d", i);
        System.out.println();
    }

    public static int[] add10(int[] b1) {
        int[] b2 = new int[b1.length]; // 宣告並配置一維陣列b2
        for (int i = 0; i < b1.length; i++)
            b2[i] = b1[i] + 10; // 將陣列b2的元素加10
        return b2; // 傳回陣列b2
    }
}
