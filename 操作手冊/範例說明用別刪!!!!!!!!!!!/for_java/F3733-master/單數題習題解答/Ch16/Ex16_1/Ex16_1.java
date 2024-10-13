// Ex16_1
class Ball<T>{
    private T color;
    public void setValue(T c){
        color=c;
    }
    public void show(){
        System.out.println("color="+color);
    }
}
public class Ex16_1{
    public static void main(String[] args){
        Ball<String> b1=new Ball<String>();
        Ball<Integer> b2=new Ball<Integer>();            
        b1.setValue("Red");
        b2.setValue(255);
        b1.show();
        b2.show();
    }
}

/* output--------
color=Red
color=255
---------------*/