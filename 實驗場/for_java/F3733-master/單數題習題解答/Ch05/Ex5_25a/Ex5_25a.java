public class Ex5_25a{
    public static void main(String[] args){
        for(int i=0;i<5;i++){           // 負責換行
            for(int j=5;j>i;j--)        // 印星號
                System.out.print("*"); 
            System.out.println(); 
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