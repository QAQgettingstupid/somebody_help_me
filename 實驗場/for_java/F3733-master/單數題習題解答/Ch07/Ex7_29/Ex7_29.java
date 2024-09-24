public class Ex7_29{
    public static void main(String[] args){        
        System.out.println("triangle(6,3)="+triangle(6,3));
        System.out.println("triangle(4.2,3.3)="+triangle(4.2f,3.3f));
    }  

    public static float triangle(int base,int height){
        return ((base*height)/2.0f);
    }

    public static float triangle(float base,float height){
        return ((base*height)/2.0f);
    }
}

/* output----------------------
triangle(6,3)=9.0
triangle(4.2,3.3)=6.9299994
-----------------------------*/