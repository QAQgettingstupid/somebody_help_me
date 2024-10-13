// Ch16_11, 以ListIterator走訪LinkedList元素
import java.util.*;
public class Ch16_11{
    public static void main(String[] args){
        LinkedList<Integer> llist=new LinkedList<Integer>();  
        llist.add(5); 	//加入元素5
        llist.add(7); 	//加入元素7
        llist.add(10); 	//加入元素10
        llist.add(14); 	//加入元素13 
        ListIterator<Integer> litr=llist.listIterator();
            
        System.out.print("正向列出LinkedList內容:");
        while(litr.hasNext())    				    // 正向走訪元素
            System.out.print(litr.next()+" ");   	// 印出元素內容
        System.out.println();
             
        System.out.print("反向列出LinkedList內容:");
        while(litr.hasPrevious())				        // 反向走訪元素
            System.out.print(litr.previous()+" ");	    // 印出元素內容
        System.out.println();      
    }
}
