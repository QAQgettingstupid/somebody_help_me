// Ch7_11, 利用引數個數的不同來多載函數的範例
public class Ch7_11{
    public static void main(String[] args){
        star();           // 呼叫 9~11行的star()函數
        star(7);          // 呼叫13~15行的star()函數
        star('@',9);      // 呼叫17~21行的star()函數
    }
    
    public static void star(){  // 沒有引數的star()函數
        star(5);           // 呼叫13~15行的star()，並傳入整數5
    }
    
    public static void star(int n){             // 有一個引數的star()函數
        star('*',n);    // 呼叫17~21行的star()，並傳入'*'和n
    }   
    
    public static void star(char ch,int n){    // 有兩個引數的star()函數
        for(int i=0;i<n;i++)
            System.out.print(ch); 
        System.out.println();                
    }
}