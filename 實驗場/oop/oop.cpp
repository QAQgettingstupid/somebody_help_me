#include <iostream>
#include <math.h>

using namespace std;

class oop{

public:

    oop(double x1, double x2, double y1, double y2) : x1(x1), x2(x2), y1(y1),y2(y2) {

    }
    void print() {
        cout <<ans<< '\n';
    }
    void distance(){
        ans = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    }

private:

    double x1;
    double x2;
    double y1;
    double y2;
    double ans;
    
};

int main()
{
    
    oop test(0, 12, 0, 5);
    test.distance();
    test.print();
    
    return 0;
}