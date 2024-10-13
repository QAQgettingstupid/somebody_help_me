// Ex9_19,
class Data{   
   private String name;
   private Test score;   
   
   class Test{
      private int english;
      private int math;
      
      public Test(int eng,int m){
         english=eng;
         math=m;
      }
      public double avg(){
         return (english+math)/2.0;
      }
   }
   public Data(String na,int eng,int ma){
      name=na;      
      score=new Test(eng,ma);
   }
   public void show(){
      System.out.println("Name: "+name);
      System.out.println("English :"+score.english);
      System.out.println("Math: "+score.math);
      System.out.println("Average: "+score.avg());
   }
}

public class Ex9_19{
   public static void main(String args[])
   {
      Data stu=new Data("Annie",85,92);
      stu.show();
   }   
}

/* output------
Name: Annie
English :85
Math: 92
Average: 88.5
-------------*/ 