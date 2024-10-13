class CBox{
    int length;
    int width;
    int height;

    int volume(){
        return length*width*height;
    }
    int surfaceArea(){
        return (length*width+width*height+height*length)*2;
    }
    void showData(){
        System.out.println("length= "+length);
        System.out.println("width= "+width);
        System.out.println("height= "+height);
    }
    void showAll(){
        showData();
        System.out.println("volume= "+volume());
        System.out.println("surface area= "+surfaceArea());
    }
}
public class Ex8_5{
    public static void main(String[] args){ 
        CBox box=new CBox();
        box.length=1;
        box.width=1;
        box.height=1;        
        box.showAll();
    }
}

/* output---------
length= 1
width= 1
height= 1
volume= 1
surface area= 6
----------------*/