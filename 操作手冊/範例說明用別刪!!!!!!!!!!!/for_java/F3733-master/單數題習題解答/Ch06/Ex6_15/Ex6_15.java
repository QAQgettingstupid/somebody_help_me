public class Ex6_15{
    public static void main(String[] args){ 
        int arr[][]={{4,2},{3,4,6},{7,4,8,5}};
        int max=arr[0][0];
  
        System.out.println("陣列arr的內容:");
        for(int[] i:arr){
            for(int j:i){
                System.out.printf("%d ",j);
                if(j>max)
                    max=j;
            }
            System.out.println();   
        }
        System.out.println("max="+max);
    }  
}

/* output-------
陣列arr的內容:
4 2 
3 4 6 
7 4 8 5
max=8
--------------*/