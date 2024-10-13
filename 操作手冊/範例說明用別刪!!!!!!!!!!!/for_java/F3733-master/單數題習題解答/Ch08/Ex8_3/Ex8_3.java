class Cddd{
    String name;
    double height;
    double weight;
}
public class Ex8_3{
    public static void main(String[] args){ 
        Cddd student=new Cddd();
        double bmi;
        student.name="Sandy";
        student.height=1.655;
        student.weight=58.2;
        bmi=student.weight/(student.height*student.height);        
        System.out.println("姓名:"+student.name);
        System.out.println("體重"+student.weight+"公斤, 身高"+student.height+"公尺");
        System.out.printf("BMI=%5.2f",bmi);
    }
}

/* output-------------------
姓名:Sandy
體重58.2公斤, 身高1.655公尺
BMI=21.25
--------------------------*/