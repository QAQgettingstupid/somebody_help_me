// Ex11_7, 多重繼承的練習
interface MyMath{
    void show();
    public void add(int a, int b);
    public void sub(int a, int b);
    public void mul(int a, int b);
    public void div(int a, int b);
}
interface AdvancedMath{
    public void mod(int a, int b);   	// 計算a%b
    public void fac(int a);			// 計算a!
    public void pow(int a, int b); 	// 計算a^b
}   
class Compute implements MyMath, AdvancedMath{
    public int ans;
    public void add(int a,int b){
        ans=a+b;
    }
    public void sub(int a,int b){
        ans=a-b;
    }
    public void mul(int a,int b){
        ans=a*b;
    }
    public void div(int a,int b){
        ans=a/b;
    }
    public void mod(int a,int b){
        ans=a%b;
    }
    public void fac(int a){
        ans=1;
        for(int i=1;i<=a;i++)
            ans*=i;
    }
    public void pow(int a,int b){
        ans=1;
        for(int i=1;i<=b;i++)
            ans*=a;
    }
    public void show(){
        System.out.println("ans="+ans);
    }
}
 
public class Ex11_7{
    public static void main(String[] args){
        Compute cp=new Compute();
        cp.mul(3,5);		
        cp.show();		// 此行會回應 "ans=15" 字串
        cp.mod(14,5);    	
        cp.show();  		// 此行會回應 "ans=4" 字串
        cp.fac(5);
        cp.show();        	// 此行會回應 "ans=120" 字串
    }
}

/* output-----
ans=15
ans=4
ans=120  
--------------*/