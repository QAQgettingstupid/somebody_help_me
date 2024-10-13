public class Ex6_11{
    public static void main(String[] args){ 
        double temp[][]={{18.2,17.3,15.0,13.4},
                        {23.8,25.1,20.6,17.8},
                        {20.6,21.5,18.4,15.7}};
        double s[]=new double[3];
        double t[]=new double[4];
        double high=temp[0][0], low=temp[0][0];
        int i, j, h_section=0, l_section=0, h_day=0, l_day=0;

        System.out.println("(a) 陣列temp的內容");
        System.out.println("       星期一  星期二  星期三  星期四");
        for(i=0;i<3;i++){
            System.out.printf("時段%d  ",(i+1));
            for(j=0;j<4;j++)
                System.out.printf("%5.1f   ",temp[i][j]);
            System.out.println();
        }

        System.out.println("\n(b) 每日的平均溫度");
        for(i=0;i<4;i++){
            for(j=0;j<3;j++)
                t[i]+=temp[j][i];
            System.out.printf("星期%d的平均溫度是%5.1f\n",(i+1),t[i]/3);
        }

        System.out.println("\n(c) 每個時段的平均氣溫");
        for(i=0;i<3;i++){
            for(j=0;j<4;j++)
                s[i]+=temp[i][j];                
            System.out.printf("時段%d的平均溫度是%5.1f\n",(i+1),s[i]/4);
        }
         
        for(i=0;i<3;i++)    
            for(j=0;j<4;j++){
                if(high<temp[i][j]){    // 找溫度最高的日子與時段
                    high=temp[i][j];
                    h_section=i;
                    h_day=j;
                }
                if(low>temp[i][j]){     // 找溫度最低的日子與時段
                    low=temp[i][j];
                    l_section=i;
                    l_day=j;
                }
            }
        System.out.println("\n(d) 溫度最高的日子與時段");
        System.out.println("星期"+(h_day+1)+"的時段"+(h_section+1));
        System.out.println("\n(e) 溫度最低的日子與時段");
        System.out.println("星期"+(l_day+1)+"的時段"+(l_section+1));         
    }  
}

/* output--------------------------------
(a) 陣列temp的內容
       星期一  星期二  星期三  星期四
時段1   18.2    17.3    15.0    13.4
時段2   23.8    25.1    20.6    17.8
時段3   20.6    21.5    18.4    15.7

(b) 每日的平均溫度
星期1的平均溫度是 20.9
星期2的平均溫度是 21.3
星期3的平均溫度是 18.0
星期4的平均溫度是 15.6

(c) 每個時段的平均氣溫
時段1的平均溫度是 16.0
時段2的平均溫度是 21.8
時段3的平均溫度是 19.1

(d) 溫度最高的日子與時段
星期2的時段2

(e) 溫度最低的日子與時段
星期4的時段1
--------------------------------------*/