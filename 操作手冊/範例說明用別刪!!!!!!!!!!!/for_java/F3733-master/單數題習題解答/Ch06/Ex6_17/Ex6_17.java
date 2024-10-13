public class Ex6_17{
    public static void main(String[] args){ 
        int min=Integer.MAX_VALUE;
        int[][][] arr={{{15,85,36},{30,14,37},
                      {47,23,96},{19,39,51}},
                     {{22,16,51},{97,30,12},
                      {68,77,26},{57,32,76}}};
  
        System.out.println("陣列arr的內容:");
        for(int i=0;i<arr.length;i++){
            for(int j=0;j<arr[i].length;j++){
                for(int k=0;k<arr[i][j].length;k++){
                    if(arr[i][j][k]<min)
                        min=arr[i][j][k];
                    System.out.print(arr[i][j][k]+"\t");
                }                    
                System.out.println();          
            }
            System.out.println();
        }
        System.out.println("最小值為"+min);
    }
}

/* output------------
陣列arr的內容:
15      85      36
30      14      37
47      23      96
19      39      51

22      16      51
97      30      12
68      77      26
57      32      76

最小值為12
-------------------*/