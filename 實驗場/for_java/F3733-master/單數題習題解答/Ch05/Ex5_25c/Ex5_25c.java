public class Ex5_25c{
    public static void main(String[] args){
        for(int i=0;i<5;i++) {          // 負責換行
            for(int j=0;j<i;j++)        // 印空白
                System.out.print(" ");
            for(int k=5;k>i;k--)        // 印星號
                System.out.print("*");              
            System.out.print("\n");
        }
    }              
}

/* output---
*****
 ****
  ***
   **
    *
----------*/