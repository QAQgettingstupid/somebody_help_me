// ex16_7
import java.util.*;
public class Ex16_7{
    public static void main(String args[]){      
        LinkedList<String> llist=new LinkedList<String>();
        ArrayList<String> alist=new ArrayList<String>();

        llist.add("apple");
        llist.add("guava");
        System.out.println("(a) LinkedList集合內容: "+llist);

        alist.add("tomato");
        alist.add("apple");
        alist.add("papaya");
        alist.add("grape");
        System.out.println("(b) ArrayList集合內容: "+alist);

        alist.addAll(llist);
        System.out.println("(c) 將llist裡的元素加入alist後, ArrayList集合內容: "+alist);

        System.out.print("(d) 第一個出現apple的索引值="+alist.indexOf("apple"));
        System.out.print(", 最後一個出現apple的索引值="+alist.lastIndexOf("apple"));
    }
}

/* output---------------------------------------------------------------------------------------
(a) LinkedList集合內容: [apple, guava]
(b) ArrayList集合內容: [tomato, apple, papaya, grape]
(c) 將llist裡的元素加入alist後, ArrayList集合內容: [tomato, apple, papaya, grape, apple, guava]
(d) 第一個出現apple的索引值=1, 最後一個出現apple的索引值=4
----------------------------------------------------------------------------------------------*/