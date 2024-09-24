// Ex16_5
import java.util.*;
public class Ex16_5{
    public static void main(String args[]){
        TreeSet<String> tset=new TreeSet<String>();
        tset.add("Speech is silver, silence is golden.");
        tset.add("Two heads are better than one.");
        tset.add("East or west, home is best.");
        tset.add("It is never too late to learn.");
        System.out.println("TreeSet的元素: "+tset);
        System.out.println("第一個元素: "+tset.first());
        System.out.println("最後一個元素: "+tset.last());
        System.out.println("小於字串Speech的元素: "+tset.headSet("Speech"));
    }
}

/* output------------------------------------------------------------------------------------------------------------------------------------------
TreeSet的元素: [East or west, home is best., It is never too late to learn., Speech is silver, silence is golden., Two heads are better than one.]
第一個元素: East or west, home is best.
最後一個元素: Two heads are better than one.
小於字串Speech的元素: [East or west, home is best., It is never too late to learn.]
-------------------------------------------------------------------------------------------------------------------------------------------------*/