public class Ex5_23{
    public static void main(String[] args){       
        int n=0;
        do{
           n++;
        }while(!((n%3==1) && (n%5==3) && (n%7==2)));
        System.out.println("共有"+n+"隻兔子");
    }
}

/* output------
共有58隻兔子
-------------*/