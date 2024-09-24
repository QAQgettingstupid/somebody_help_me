public class Ex7_31{
    public static void main(String[] args){ 
        int[] arr={12,7,32,67};
        System.out.println("smallest(8,9)="+smallest(8,9));
        System.out.print("arr=");
        for(int i=0;i<arr.length;i++)
            System.out.print(arr[i]+" ");
        System.out.println("\nsmallest(arr)="+smallest(arr));
    }  

    public static int smallest(int a,int b){
        if(a<b)
            return a;
        else
            return b;
    }

    public static int smallest(int[] arr){
        int small=arr[0];
        for(int i=0;i<arr.length;i++)
            if(small>arr[i])
                small=arr[i];
        
        return small;
    }
}

/* output---------
smallest(8,9)=8
arr=12 7 32 67 
smallest(arr)=7
----------------*/