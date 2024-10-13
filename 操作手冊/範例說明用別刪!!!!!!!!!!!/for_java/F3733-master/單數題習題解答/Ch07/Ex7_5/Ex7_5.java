public class Ex7_5{
    public static void main(String[] args){
        System.out.println("fahrenheit(50)="+fahrenheit(50));
    } 

    public static double fahrenheit(double c){
        double f=0;
        f=(9/5.0)*c+32;
        return f;            
    }     
}

/* output--------------
fahrenheit(50)=122.0
---------------------*/