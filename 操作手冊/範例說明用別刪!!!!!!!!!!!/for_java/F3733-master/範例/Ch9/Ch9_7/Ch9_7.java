// Ch9_7,「類別函數」的使用
class Circle{
    private static int count=0;		// 宣告count為類別變數
    private static double pi=3.14;	// 宣告pi為類別變數
    private double radius;
 
    public Circle(){ 			// 沒有引數的Circle()建構子         
        this(1.0);       			// 呼叫第10行的建構子，並傳入1.0
    } 
    public Circle(double r){ 		// 有一個引數的Circle()建構子
        radius=r;
        count++;       			// 當此建構子被呼叫時，count便加1
    } 
    public void show(){         
        System.out.printf("area=%6.2f\n",pi*radius*radius);
    }
    public static void show_count(){  // 顯示目前物件建立的個數 
        System.out.println(count+" object(s) created"); 
    } 
}
public class Ch9_7{
    public static void main(String[] args){
        Circle.show_count();	   	// 用Circle類別呼叫show_count()
        Circle c1=new Circle();	// 呼叫第7行的建構子
        Circle.show_count();	   	// 用Circle類別呼叫show_count()
        Circle c2=new Circle(2.0);	// 呼叫第10行的建構子
        Circle c3=new Circle(4.3);	// 呼叫第10行的建構子     
        c3.show_count();		  	// 用c3物件呼叫show_count()
    }
}