// Ex16_13
import java.util.*;
public class Ex16_13{
    public static void main(String args[]){      
        ArrayList<Integer> alist=new ArrayList<Integer>();
        for(int i=1;i<=10;i++)
            alist.add((int)(Math.random()*100));
        System.out.print("ArrayList集合內容: ");
        for(int i:alist)
            System.out.print(i+" ");
    }
}

/* output---------------------------------------
ArrayList集合內容: 88 31 87 21 83 16 61 3 48 80 
----------------------------------------------*/