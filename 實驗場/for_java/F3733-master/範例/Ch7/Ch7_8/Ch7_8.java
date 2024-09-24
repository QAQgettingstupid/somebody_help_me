// Ch7_8,直接修改陣列裡的元素
public class Ch7_8{
    public static void main(String[] args){
        int[] a1={18,32,65,27,30};	// 宣告一維陣列a1
        add10(a1);     	// 呼叫add10()
        for(int e:a1)  	// 印出陣列的內容
            System.out.printf("%3d",e); 
    }
  
    public static void add10(int[] b1){
        for(int i=0;i<b1.length;i++)
            b1[i]=b1[i]+10;         // 將陣列元素加10
    }
}