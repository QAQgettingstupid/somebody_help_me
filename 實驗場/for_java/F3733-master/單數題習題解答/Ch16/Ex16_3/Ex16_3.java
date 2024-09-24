// Ex16_3
import java.util.*;
public class Ex16_3{
    public static void main(String args[]){
        HashSet<Integer> h1=new HashSet<Integer>();
        TreeSet<Integer> t1=new TreeSet<Integer>();

        h1.add(36);
        h1.add(15);

        t1.add(52);
        t1.add(23);
        t1.add(32);
        t1.add(69);
        t1.add(10);
        t1.add(7);
        t1.add(36);
        t1.add(15);

        System.out.println("h1集合元素:"+h1);
        System.out.println("t1集合元素:"+t1);

        if(t1.contains(32)){
            t1.remove(32);
            System.out.println("t1刪除元素32...");
            System.out.println("t1集合元素:"+t1);
        }
        else
            System.out.println("t1集合中不包含32");

        System.out.print("t1集合包含"+h1+"嗎? ");
        if(t1.containsAll(h1))
            System.out.println("Yes!");
        else
            System.out.println("No!");
    }
}

/* output------------------------------------
h1集合元素:[36, 15]
t1集合元素:[7, 10, 15, 23, 32, 36, 52, 69]
t1刪除元素32...
t1集合元素:[7, 10, 15, 23, 36, 52, 69]
t1集合包含[36, 15]嗎? Yes!
-------------------------------------------*/