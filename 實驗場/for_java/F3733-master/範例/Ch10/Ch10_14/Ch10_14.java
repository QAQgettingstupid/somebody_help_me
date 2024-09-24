// Ch10_14, 改寫Object類別裡的toString() 函數
class Caaa{
    private int num;
    
    public Caaa(int n){
       num=n;
    }  
    public String toString(){    // 改寫toString() 函數   
       String str="toString() called, num="+num;
       return str;      
    }
}   
public class Ch10_14{
    public static void main(String[] args){   
       Caaa a=new Caaa(2);
       System.out.println(a.toString());   // 印出物件a的內容
    }
}
 