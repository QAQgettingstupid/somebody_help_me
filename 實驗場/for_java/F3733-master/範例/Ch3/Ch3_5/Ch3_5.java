// Ch3_5, 溢位的發生
public class Ch3_5{
    public static void main(String[] args){
        int i=java.lang.Integer.MAX_VALUE;       // 將i設為int型別的最大值

        System.out.println("i="+i);
        System.out.println("i+1="+(i+1));        // 會發生溢位
        System.out.println("i+2="+(i+2));        // 會發生溢位
    }
}