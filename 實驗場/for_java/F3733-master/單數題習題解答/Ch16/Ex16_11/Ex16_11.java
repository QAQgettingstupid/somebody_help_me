// Ex16_11
import java.util.*;
public class Ex16_11{
    public static void main(String args[]){      
        int count=0,key=0;
        TreeMap<Integer,Integer> tmap=new TreeMap<Integer,Integer>();

        while(count<=4){
            key=(int)(100*Math.random());
            if(!tmap.containsKey(key)){
                tmap.put(key,count);
                count++;
            }
        }
        System.out.println("TreeMap集合內容: "+tmap);

        HashSet<Integer> hset=new HashSet<Integer>();
        key=0;
        while(key<=100){
            if(tmap.containsKey(key))
                hset.add(key);
            key++;
        }
        System.out.println("HashSet集合內容: "+hset);
    }
}

/* output---------------------------------------
TreeMap集合內容: {17=3, 34=4, 43=2, 82=1, 85=0}
HashSet集合內容: [17, 34, 82, 85, 43]
----------------------------------------------*/