// Ch12_10, StringBuffer類別使用的範例
public class Ch12_10{
    public static void main(String args[]){
        StringBuffer s1=new StringBuffer("Black & White");
      
        System.out.println(s1); 
        System.out.println("length="+s1.length());
        System.out.println(s1.replace(0,5,"cats"));
        System.out.println(s1.replace(7,12,"dogs"));
        System.out.println(s1.reverse());
        System.out.println(s1); 
   }
}

/* output-----
Black & White
length=13
cats & White
cats & dogs
sgod & stac
sgod & stac 
-------------*/