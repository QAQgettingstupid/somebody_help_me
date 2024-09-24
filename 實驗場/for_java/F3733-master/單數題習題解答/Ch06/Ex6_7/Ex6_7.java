public class Ex6_7{
    public static void main(String[] args){        
        int[] arr={12,15,8,43};
        int[] arr2=new int[4];

        System.out.print("arr[]元素: ");
        for(int i=0;i<arr.length;i++){
            System.out.printf("%d ",arr[i]);
            arr2[(arr.length-i)-1]=arr[i];
        }
        System.out.print("\narr2[]元素: ");
        for(int i=0;i<arr2.length;i++)
            System.out.printf("%d ",arr2[i]);           
    }  
}

/* output----------------
arr[]元素: 12 15 8 43 
arr2[]元素: 43 8 15 12 
-----------------------*/