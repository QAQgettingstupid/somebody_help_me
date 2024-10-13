public class Ex6_5{
    public static void main(String[] args){        
        int[] arr={32,16,34,71};
        int sum=0;

        System.out.print("arr[]元素: ");
        for(int i=0;i<arr.length;i++){
            System.out.printf("%d ",arr[i]);
            sum+=arr[i];
        } 
        System.out.printf("\n平均值為%5.2f",(float)sum/arr.length);
    }
}

/* output---------------
arr[]元素: 32 16 34 71 
平均值為38.25
----------------------*/