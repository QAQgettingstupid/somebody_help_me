//Ch3_3, 二進位、八進位和十六進位的使用
public class Ch3_3{
    public static void main(String[] args){
        byte bin=0b1111;		    // 以二進位表示的整數
        short oct=02001;		    // 以八進位表示的整數
        int hex1=0xff12; 	         // 以十六進位表示的整數
        long hex2=0x12345ffeL;	    // 以十六進位表示的長整數
      
        System.out.println("bin= " + bin);
        System.out.println("oct= " + oct);
        System.out.println("hex1= " + hex1);
        System.out.println("hex2= " + hex2);
    }
}