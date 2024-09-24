package pack12_9.sub1;
public abstract class MyMath{    
    protected int ans;
    public void show(){
        System.out.println("ans="+ans);
    }
    public abstract void add(int a,int b);  // 計算a+b
    public abstract void sub(int a,int b);  // 計算a-b
    public abstract void mul(int a,int b);  // 計算a*b
    public abstract void div(int a,int b);  // 計算a/b  
}