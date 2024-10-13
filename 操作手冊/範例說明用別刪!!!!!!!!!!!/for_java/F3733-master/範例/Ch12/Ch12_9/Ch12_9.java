// Ch12_9, String類別使用的範例
public class Ch12_9{
    public static void main(String[] args){
        String s1="Easier said than done.";
        System.out.println("length="+s1.length());
        System.out.println("charAt(8)="+s1.charAt(8));
        System.out.println("sub string="+s1.substring(7)); 
        System.out.println("start with \"th\"="+s1.startsWith("th"));
        System.out.println("upper case="+s1.toUpperCase());
    }
 }
 

/* output--------------------------
length=22
charAt(8)=a
sub string=said than done.
start with "th"=false
upper case=EASIER SAID THAN DONE. 
---------------------------------*/