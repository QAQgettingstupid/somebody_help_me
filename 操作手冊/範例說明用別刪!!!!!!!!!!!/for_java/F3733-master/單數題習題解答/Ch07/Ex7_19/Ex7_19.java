public class Ex7_19{
    public static void main(String[] args){
        int[][] arr={{75,89,10},{38,45,16}};
        System.out.println("陣列arr=");
        for(int r=0;r<arr.length;r++){
            for(int c=0;c<arr[r].length;c++)
                System.out.print(arr[r][c]+" ");
            System.out.println();  
        }                
        System.out.println("最大元素值:"+argmin(arr));                             
    }  

    public static int argmin(int[][] arr){
        int max=arr[0][0];
        for(int r=0;r<arr.length;r++){
            for(int c=0;c<arr[r].length;c++)
                if(arr[r][c]>max)
                    max=arr[r][c];                
            }
        return max;
    }     
}

/* output----
陣列arr=
75 89 10 
38 45 16
-----------*/