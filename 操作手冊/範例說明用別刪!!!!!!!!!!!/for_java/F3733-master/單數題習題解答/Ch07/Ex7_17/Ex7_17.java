public class Ex7_17{
    public static void main(String[] args){
        int[] arr={75,29,38,45,16};
        System.out.print("arr[]=");
        for(int i=0;i<arr.length;i++)
            System.out.printf("%d ",arr[i]);           
        System.out.println("\n最小的元素值:"+min(arr));                             
    }  

    public static int min(int[] arr){
        int n=arr[0];
        for(int i=0;i<arr.length;i++)
            if(arr[i]<n)
                n=arr[i];
        return n;
    }     
}

/* output-------------
arr[]=75 29 38 45 16 
最小的元素值:16   
--------------------*/