public class Ex7_23{
    public static void main(String[] args){
        int[][] arr={{1,3,5},{8,9,2}};

        System.out.println("平方前, 陣列arr=");
        show_array(arr);
        square(arr);
        System.out.println("平方後, 陣列arr=");
        show_array(arr);                  
    }  

    public static void square(int[][] arr){ 
        for(int r=0;r<arr.length;r++)
            for(int c=0;c<arr[r].length;c++)
                arr[r][c]*=arr[r][c];               
    } 
    
    public static void show_array(int [][] arr){        
        for(int r=0;r<arr.length;r++){
            for(int c=0;c<arr[r].length;c++)
                System.out.printf("%2d ",arr[r][c]);
            System.out.println(); 
        } 
    }
}

/* output-----------
平方前, 陣列arr=
 1  3  5 
 8  9  2
平方後, 陣列arr=
 1  9 25
64 81  4
-----------------*/