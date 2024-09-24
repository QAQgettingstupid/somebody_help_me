// Ch3_12, 格式化列印
public class Ch3_12{
    public static void main(String[] args){
        byte bt=65;         
        float ft=3.14f;
        double db=567.1234;

        System.out.printf("bt=%c\n",bt);    		// 列印字元
        System.out.printf("bt=%+05d\n",bt);		// 列印整數
        System.out.printf("oct=%o, hex=%x\n",bt, bt);  // 以不同進位數列印
        System.out.printf("ft=%7.4f\n",ft); 		// 列印浮點數
        System.out.printf("db=%f\n",db); 		// 列印倍精度浮點數
    }
}