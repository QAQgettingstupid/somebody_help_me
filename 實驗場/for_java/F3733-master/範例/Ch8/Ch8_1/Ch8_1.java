// Ch8_1, 建立物件與資料成員的設定 
class Rectangle{ 			// 定義Rectangle類別
    int width; 				// 宣告資料成員width 
    int height; 			// 宣告資料成員height
}

public class Ch8_1{
    public static void main(String[] args){
        Rectangle r1;
        r1=new Rectangle();	// 建立新的物件
 
        r1.width=20; 		// 設定矩形r1的寬
        r1.height=15;	// 設定矩形r1的高
        System.out.println("width="+r1.width);    // 印出r1.width
        System.out.println("height="+r1.height);  // 印出r1.height
    }
}