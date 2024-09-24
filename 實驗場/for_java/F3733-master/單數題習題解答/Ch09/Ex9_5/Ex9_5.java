// Ex9_5, 找出最大值和最小值
class Average{
   private int[][] arr;
   private double avg;
   public Average(int[][] a){
      arr=a;
      double sum=0;
      int cnt=0;
      for(int[] row: arr)
         for(int e:row){
            sum+=e;
            cnt++;
         }
      avg=sum/cnt;
   }
   
   public void print_avg(){
      System.out.printf("average=%6.2f\n",avg);
   }
   public void print_arr(){
      for(int[] row: arr){
         for(int e:row)
            System.out.printf("%3d",e);
         System.out.println();
      }
   }
}

public class Ex9_5{
   public static void main(String[] args){
      int[][] a={{12,54,23},{21,12,25}};
      Average obj=new Average(a);
      obj.print_avg();
      obj.print_arr();
   }
}

/* output---------
average= 24.50
 12 54 23
 21 12 25
----------------*/ 