public class Ex6_3{
    public static void main(String[] args){        
        int[] arr={53,27,69,12,3,96};
        int odd=0, even=0, odd_max=1, even_max=0;

        System.out.print("(a) ");
        for(int i=0;i<arr.length;i++)
            System.out.printf("%d ",arr[i]);
            
        System.out.print("\n(b) ");
        for(int i=0;i<arr.length;i++){        
            if(arr[i]%2!=0){
                odd++;
                if(arr[i]>odd_max)
                    odd_max=arr[i]; 
            }               
            else{
                even++;
                if(arr[i]>even_max)
                    even_max=arr[i];                 
            }                
        }
        System.out.printf("偶數有%d個, 奇數有%d個\n",even,odd);        
        System.out.println("(c) 奇數最大值: "+odd_max);
        System.out.println("(d) 偶數最大值: "+even_max);
    }
}

/* output------------------
(a) 53 27 69 12 3 96 
(b) 偶數有2個, 奇數有4個
(c) 奇數最大值: 69
(d) 偶數最大值: 96
-------------------------*/