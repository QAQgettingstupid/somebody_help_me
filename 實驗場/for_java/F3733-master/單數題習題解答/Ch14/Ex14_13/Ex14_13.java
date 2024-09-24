// Ex14_13
import java.io.*;
class Car{
    public String module;
    public String color;
    public int price;
   
    public Car(){}
    public Car(String m,String c,int p)   {
        module=m;
        color=c;
        price=p;
    }
    public void writeData(FileOutputStream fo) throws IOException{     
        String str=module+"\r\n"+color+"\r\n";    
        str+=Integer.toString(price)+"\r\n";      
        byte data[]=str.getBytes();
        fo.write(data);
    }  
    public void show(){     
        System.out.println("車款: "+module);
        System.out.println("顏色: "+color);
        System.out.println("車價: "+price+"\n");        
    } 
}
public class Ex14_13{
    public static void main(String args[]) throws IOException{          
        FileOutputStream fo=new FileOutputStream("C:\\MyJava\\Ex14_13\\mycar.txt");
        FileInputStream fi=new FileInputStream("C:\\MyJava\\Ex14_13\\mycar.txt");
        Car c1=new Car("C 300 Estate","white",297);
        Car c2=new Car("5-Series Sedan M5","black",716);
       
        c1.writeData(fo);
        c2.writeData(fo);
        fo.close();
       
        readData(fi);
        fi.close();      
    }
    
    public static void readData(FileInputStream fi) throws IOException{     
        Car s=new Car();
        byte data[]=new byte[fi.available()];
        fi.read(data);
        String str=new String(data);
        String str2[]=str.split("\r\n");
        int count=0;
        for(int i=0;i<str2.length;i++){          
            if(count==0)
                s.module=str2[i];
            if(count==1)
                s.color=str2[i];
            if(count==2){
                s.price=Integer.parseInt(str2[i]);
                count=-1;
                s.show();
            } 
            count++;                    
        }         
    }   
}

/* output-----------------
車款: C 300 Estate
顏色: white
車價: 297

車款: 5-Series Sedan M5
顏色: black
車價: 716
------------------------*/