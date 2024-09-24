class Caaa{
    int a;
    int b;
    int c;
}
public class Ex8_1{
    public static void main(String[] args){ 
        Caaa obj=new Caaa();
        obj.a=5;
        obj.b=3;
        obj.c=obj.a*obj.b;
        System.out.println("obj.a="+obj.a);
        System.out.println("obj.b="+obj.b);
        System.out.println("obj.c="+obj.c); 
    }
}

/* output----
obj.a=5
obj.b=3 
obj.c=15
-----------*/