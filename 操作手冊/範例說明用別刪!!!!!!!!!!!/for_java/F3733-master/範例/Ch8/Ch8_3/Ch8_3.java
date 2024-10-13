// Ch8_3, 函數的建立
class Rectangle{
    int width; 
    int height; 
   
    int area(){       			// 定義函數成員area(), 用來計算面積   
        return width*height;		// 傳回矩形的面積
    }
    int perimeter(){			// 定義函數成員perimeter(), 用來計算周長   
        return 2*(width+height);	// 傳回矩形的周長
    }
}

public class Ch8_3{
    public static void main(String[] args){
        Rectangle r1;
        r1=new Rectangle();    	// 建立新的物件
 
        r1.width=20;    			// 設定矩形r1的寬
        r1.height=15;   			// 設定矩形r1的高
        System.out.println("area="+r1.area());
        System.out.println("perimeter="+r1.perimeter());
    }
}