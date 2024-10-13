public class Ex6_13{
    public static void main(String[] args){ 
        int arr[][]={{18,21,30},{40,34,61},{41,15,18}};        
        int min=arr[0][0],r_index=0,c_index=0;

        System.out.println("陣列arr內容:");
        for(int i=0;i<arr.length;i++){
            for(int j=0;j<arr[i].length;j++){
                System.out.print(arr[i][j]+"\t");
                if(arr[i][j]<min){
                    min=arr[i][j];
                    r_index=i;
                    c_index=j;
            }
         }
         System.out.println();
      }
      System.out.print("\n最小值的索引值為[");
      System.out.println(r_index+"]["+c_index+"]");
    }  
}

/* output----------------
陣列arr內容:
18      21      30
40      34      61
41      15      18

最小值的索引值為[2][1]
----------------------*/