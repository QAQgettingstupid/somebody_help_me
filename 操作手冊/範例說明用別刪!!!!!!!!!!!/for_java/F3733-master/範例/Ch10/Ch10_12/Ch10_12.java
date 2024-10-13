// Ch10_12, 利用equals()判別兩個類別變數是否指向同一個物件
class Caaa{      	// 定義Caaa類別
}   
 public class Ch10_12{
    public static void main(String[] args){
       Caaa a=new Caaa();   
       Caaa b=new Caaa();   
       Caaa c=a;    	    // 宣告類別變數c，並讓它指向變數a所指向的物件
       System.out.println("a.equals(b)="+a.equals(b)); 
       System.out.println("a.equals(c)="+a.equals(c)); 
    }
}