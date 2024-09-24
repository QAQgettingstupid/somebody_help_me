// Ex12_9.java
package pack12_9;
import pack12_9.sub2.Compute;
public class Ex12_9{
    public static void main(String args[]){
        Compute cmp=new Compute();
        cmp.mul(3,5);  // 計算3*5
        cmp.show();         // 此行會回應"ans=15"字串 
    }
}

/*output-----
ans=15
-----------*/