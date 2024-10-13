// Ex16_15
import java.util.*;
public class Ex16_15{
    public static void main(String args[]){      
        int sum=0;
        LinkedList<Integer> llist=new LinkedList<Integer>();

        for(int i=1;i<=10;i++)
            llist.add((int)(Math.random()*100));
        System.out.println("LinkedList集合內容:"+llist);

        ListIterator<Integer> litr=llist.listIterator(llist.size());
        System.out.print("反向走訪LinkedList集合內容:");
        while(litr.hasPrevious()){
            int elm=litr.previous();
            System.out.print(elm+" ");
            sum+=elm;
        }
        System.out.println("\nsum="+sum);
    }
}

/* output--------------------------------------------------
LinkedList集合內容:[64, 84, 55, 83, 74, 36, 17, 8, 66, 42]
反向走訪LinkedList集合內容:42 66 8 17 36 74 83 55 84 64 
sum=529
----------------------------------------------------------*/