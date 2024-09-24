// Ex14_11
import java.io.*;
public class Ex14_11{
    public static void main(String args[]) throws IOException{
        FileOutputStream fo=new FileOutputStream("C:\\Myjava\\Ex14_11\\rand99.txt");
        FileInputStream fi=new FileInputStream("C:\\Myjava\\Ex14_11\\rand99.txt");

        int c[]=new int[5];
      
        writeData(fo);      
        fo.close();
        cnt(c,fi);
        fi.close(); 
    }
    public static void writeData(FileOutputStream fo) throws IOException{
        int count=0;
        do{
            float d= (float)Math.random()*1000;
            int num=Math.round((float)d)%123;
            String str=Character.toString((char)num);
            if(num>=97 && num<=122){    
                byte data[]=str.getBytes();     
                fo.write(data);
                count++;
            }        
        }while(count<100);
    }
    public static void cnt(int c[],FileInputStream fi) throws IOException{
        byte d[]=new byte[fi.available()];
        fi.read(d);      
        String str=new String(d);            
        char str2[]=str.toCharArray();          

        for(int i=0;i<str2.length;i++){                
            if(str2[i]=='a')
                c[0]++;
            else if(str2[i]=='e')
                c[1]++;
            else if(str2[i]=='i')
                c[2]++;
            else if(str2[i]=='o')
                c[3]++;
            else if(str2[i]=='u')
                c[4]++;   
        }
        System.out.println("a 出現"+c[0]+"次");
        System.out.println("e 出現"+c[1]+"次");
        System.out.println("i 出現"+c[2]+"次");
        System.out.println("o 出現"+c[3]+"次");
        System.out.println("u 出現"+c[4]+"次");
       }       
}

/* output------
a 出現6次
e 出現2次
i 出現3次
o 出現3次
u 出現2次
------------*/