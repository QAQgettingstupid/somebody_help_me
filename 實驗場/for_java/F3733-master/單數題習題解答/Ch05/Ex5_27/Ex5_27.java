public class Ex5_27{
    public static void main(String[] args){
        int length=3500,day=1;

        while(length>=3){
            System.out.println("length="+length+", days="+day);
            length/=2;            
            day++;
            if(length<3)
                break;
        }
        System.out.println("It spent "+(day-1)+" days");
    }
}

/* output-------------
length=3500, days=1
length=1750, days=2
length=875, days=3
length=437, days=4
length=218, days=5
length=109, days=6
length=54, days=7
length=27, days=8
length=13, days=9
length=6, days=10
length=3, days=11
It spent 11 days
--------------------*/