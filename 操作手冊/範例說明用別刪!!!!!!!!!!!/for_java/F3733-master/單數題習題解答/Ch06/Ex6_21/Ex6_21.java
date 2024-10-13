public class Ex6_21{
    public static void main(String[] args){ 
        int[] a={1,2,3,4};
        int[] b={9,8,7,6}; 
        int[] c=new int[a.length];       
  
        System.out.println("對調前, 陣列a的內容:");
        for(int i=0;i<a.length;i++)
            System.out.print(a[i]+" ");         
        System.out.println("\n對調前, 陣列b的內容:");
        for(int i=0;i<b.length;i++)
            System.out.print(b[i]+" ");
        System.out.println();         
        
        c=a;
        a=b;
        b=c;

        System.out.println("\n對調後, 陣列a的內容:");
        for(int i=0;i<a.length;i++)
            System.out.print(a[i]+" ");         
        System.out.println("\n對調後, 陣列b的內容:");
        for(int i=0;i<b.length;i++)
            System.out.print(b[i]+" ");
        System.out.println(); 
    }
}

/* output-------------
對調前, 陣列a的內容:
1 2 3 4 
對調前, 陣列b的內容:
9 8 7 6 

對調後, 陣列a的內容:
9 8 7 6 
對調後, 陣列b的內容:
1 2 3 4 
--------------------*/