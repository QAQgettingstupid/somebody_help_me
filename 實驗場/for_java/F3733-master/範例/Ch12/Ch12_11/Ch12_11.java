// Ch12_11, Integer class 函數的應用
public class Ch12_11{
    public static void main(String args[]){
        String s1;
        int inum;
  
        inum=Integer.parseInt("654")+3;	   // 將字串轉成整數後，再加3
        System.out.println(inum);
        s1=Integer.toString(inum)+"3";	   // 將 "3" 附加在字串後面
        System.out.println(s1);      
    }
 }


/* output-----
657
6573
------------*/