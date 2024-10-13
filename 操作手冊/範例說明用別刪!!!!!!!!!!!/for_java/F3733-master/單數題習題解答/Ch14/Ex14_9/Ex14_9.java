// Ex14_9,
import java.io.*;
public class Ex14_9{
    public static void main(String args[]) throws IOException{
        FileReader fr1=new FileReader("C:\\Myjava\\Ex14_9\\aaa.txt");
        FileReader fr2=new FileReader("C:\\Myjava\\Ex14_9\\bbb.txt");
        FileWriter fw=new FileWriter("C:\\Myjava\\Ex14_9\\ccc.txt");
        BufferedReader bfr1=new BufferedReader(fr1);
        BufferedReader bfr2=new BufferedReader(fr2);
        BufferedWriter bfw=new BufferedWriter(fw);
        String str;

        while((str=bfr1.readLine())!=null){
            bfw.write(str);
            bfw.newLine();
        }
        while((str=bfr2.readLine())!=null){
            bfw.write(str);
            bfw.newLine();
        }
        bfw.flush();
        fw.close();
        fr1.close();
        fr2.close();

        FileReader fr3=new FileReader("C:\\Myjava\\Ex14_9\\aaa.txt");
        FileReader fr4=new FileReader("C:\\Myjava\\Ex14_9\\bbb.txt");
        FileReader fr5=new FileReader("C:\\Myjava\\Ex14_9\\ccc.txt");
        BufferedReader bfr3=new BufferedReader(fr3);
        BufferedReader bfr4=new BufferedReader(fr4);
        BufferedReader bfr5=new BufferedReader(fr5); 
        // 印出檔案內容
        System.out.println("aaa.txt");
        while((str=bfr3.readLine())!=null)
           System.out.println(str);
  
        System.out.println("\nbbb.txt");
        while((str=bfr4.readLine())!=null)
           System.out.println(str);
  
        System.out.println("\nccc.txt");
        while((str=bfr5.readLine())!=null)
            System.out.println(str);       
        fr3.close();
        fr4.close();
        fr5.close();
    }
}

/*output--------------------------
aaa.txt
Look before you leap.

bbb.txt
Make hay while the sun shines.

ccc.txt
Look before you leap.
Make hay while the sun shines.
--------------------------------*/