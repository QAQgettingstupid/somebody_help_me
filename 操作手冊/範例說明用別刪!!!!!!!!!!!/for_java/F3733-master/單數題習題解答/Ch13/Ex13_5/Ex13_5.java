// Ex13_5
public class Ex13_5{
    public static void main(String args[]){
        int num=5;
        int[] d={3,0,0,1};
        for(int i=0;i<d.length;i++){
            try{            
                System.out.println(num+"/"+d[i]+"= "+num/d[i]);
            }
            catch(ArithmeticException e){ 
                System.out.println("除數為"+d[i]+"不計算");
                continue;            
            }
        }
    }
}
 
/* output----
5/3= 1
除數為0不計算
除數為0不計算
5/1= 5
-----------*/