// Ch7_10, 函數的多載-引數型別不同
public class Ch7_10{
    public static void main(String[] args){
        int a=5, b[]={1,2,3,4};
        show(a);      					// 將整數a傳遞到show()裡
        show(b);      					// 將整數陣列b傳遞到show()
    }
   
    public static void show(int i) {      	// 定義show(),可接收整數變數
        System.out.println("value= "+i);
    }    
    public static void show(int arr[]){ 	// 定義show(),可接收整數陣列   
        System.out.print("array=");
        for(int i=0;i<arr.length;i++)
            System.out.printf("%2d",arr[i]); 
    }
}