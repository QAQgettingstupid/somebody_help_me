// ex16_9
import java.util.*;
public class Ex16_9{
    public static void main(String args[]){      
        HashMap<Integer,Integer> hmap=new HashMap<Integer,Integer>();
        for(int i=0;i<5;i++)
            hmap.put(i,(int)(100*Math.random()));

        TreeSet<Integer> tset=new TreeSet<Integer>(hmap.values());
        HashSet<Integer> hset=new HashSet<Integer>(hmap.keySet());

        System.out.println("HashMap集合內容: "+hmap);
        System.out.println("TreeSet集合內容: "+tset);
        System.out.println("HashSet集合內容: "+hset);
    }
}

/* output---------------------------------------
HashMap集合內容: {0=87, 1=93, 2=50, 3=97, 4=47}
TreeSet集合內容: [47, 50, 87, 93, 97]
HashSet集合內容: [0, 1, 2, 3, 4]
----------------------------------------------*/