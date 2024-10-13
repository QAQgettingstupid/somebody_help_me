// Ex14_3
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
public class Ex14_3{
    public static void main(String args[])throws IOException{
    int n,sum=0;
    BufferedReader buf;
    String str;
    buf=new BufferedReader(new InputStreamReader(System.in));

    System.out.print("請輸入一個整數: ");
    str=buf.readLine();
    n=Integer.parseInt(str);

    for(int i=1;i<=n;i++)
        sum+=i;
    System.out.println("1+2+...+"+n+"="+sum);      
    }
}

/*output------------
請輸入一個整數: 10
1+2+...+10=55
------------------*/