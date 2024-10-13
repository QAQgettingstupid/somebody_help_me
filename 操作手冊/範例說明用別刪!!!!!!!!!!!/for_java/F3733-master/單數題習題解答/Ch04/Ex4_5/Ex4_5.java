public class Ex4_5{
    public static void main(String[] args){
        System.out.printf("(a) 6+4<9+12: %b\n",6+4<9+12);
        System.out.printf("(b) 16+7>=6+9: %b\n",16+7>=6+9);
        System.out.printf("(c) 13-6==7+8: %b\n",13-6==7+8);
        System.out.printf("(d) 7>0 && 6<6 && 12<13: %b\n",7>0 && 6<6 && (12<13));
        System.out.printf("(e) 8>0 || 12<7: %b\n",(8>0) || (12<7));
        System.out.printf("(f) 8<=8: %b\n",8<=8);
        System.out.printf("(g) 7+7>15: %b\n",7+7>15);
        System.out.printf("(h) 19+34-6>4: %b\n",19+34-6>4);
        System.out.printf("(i) 12+7>0 || 13-5>6: %b\n",12+7>0 ||(13-5>6));
        System.out.printf("(j) 3>=5: %b\n",3>=5);
    }
}

/* output--------------------------
(a) 6+4<9+12: true
(b) 16+7>=6+9: true
(c) 13-6==7+8: false
(d) 7>0 && 6<6 && 12<13: false
(e) 8>0 || 12<7: true
(f) 8<=8: true
(g) 7+7>15: false
(h) 19+34-6>4: true
(i) 12+7>0 || 13-5>6: true
(j) 3>=5: false
--------------------------------*/