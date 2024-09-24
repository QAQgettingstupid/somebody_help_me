public class Ex2_17{
    public static void main(String[] args){     // main()
        int a=2, b=3, c=4;  
        System.out.println(a+"+"+b+"+"+c+"="+(a+b+c));       
    }
}

/* 程式錯誤之處
02行，#不能做為註解
03行，宣告多個變數要用逗號(,)分開
04行列印a+b+c的結果，要用括號將a+b+c包圍起來，
04行敘述結束沒加上分號;
*/

/* 修正後的執行結果----
2+3+4=9
--------------------*/