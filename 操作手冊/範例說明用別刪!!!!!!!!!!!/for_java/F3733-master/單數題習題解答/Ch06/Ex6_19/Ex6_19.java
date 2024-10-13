public class Ex6_19{
    public static void main(String[] args){ 
        int[][][] arr={{{82,13,21},{49,12,6},
                      {4,18,30},{50,24,62}},
                     {{7,9,14},{20,43,19},
                      {20,68,33},{15,17,38}}};
  
        for(int i=0;i<arr.length;i++){
            for(int j=0;j<arr[i].length;j++){
                for(int k=0;k<arr[i][j].length;k++)
                    if(arr[i][j][k]%2==0)
                        arr[i][j][k]=0;
            }
        }

        System.out.println("陣列arr的內容:");
        for(int i=0;i<arr.length;i++){
            for(int j=0;j<arr[i].length;j++){
                for(int k=0;k<arr[i][j].length;k++)
                    System.out.print(arr[i][j][k]+"\t");
                System.out.println();          
            }
            System.out.println();
        }
    }
}

/* output------------
陣列arr的內容:
0       13      21
49      0       0
0       0       0
0       0       0

7       9       0
0       43      19
0       0       33
15      17      0

--------------------*/