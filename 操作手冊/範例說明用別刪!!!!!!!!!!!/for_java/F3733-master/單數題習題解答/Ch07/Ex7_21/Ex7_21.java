public class Ex7_21{
    public static void main(String[] args){
        int[] arr={7,3,2,4,5};
        System.out.print("arr[]=");
        for(int i=0;i<arr.length;i++)
            System.out.printf("%d ",arr[i]);           
        System.out.println("乘積="+product(arr));                             
    }  

    public static int product(int[] arr){
        int min=arr[0];
        int max=arr[0];
        for(int i=0;i<arr.length;i++){
            if(arr[i]<min)
                min=arr[i];
            if(arr[i]>max)
                max=arr[i];
        }
        System.out.println("\n最大值為"+max+", 最小值為"+min);
        return max*min;
    }     
}

/* output-------------
arr[]=7 3 2 4 5 
最大值為7, 最小值為2
乘積=14
--------------------*/