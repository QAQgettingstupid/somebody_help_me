// Ch8_2, 同時建立兩個物件
class Rectangle{
    int width;         // 定義資料成員width 
    int height;        // 定義資料成員height
}

public class Ch8_2{
    public static void main(String[] args){
        Rectangle r1,r2;			// 宣告指變數r1,r2
        r1=new Rectangle();  		// 建立物件r1
        r2=new Rectangle();   		// 建立物件r2  
 
        r1.width=20;    			// 設定矩形r1的寬
        r1.height=15;    			// 設定矩形r1的高
        r2.width=25;    			// 設定矩形r2的寬
        r2.height=r1.height+3;		// 設定矩形r2的高
    
        System.out.println("r1.width="+r1.width);
        System.out.println("r1.height="+r1.height);
        System.out.println("r2.width="+r2.width);
        System.out.println("r2.height="+r2.height);
    }
}