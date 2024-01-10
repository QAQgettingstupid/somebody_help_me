#include <iostream>

using namespace std;

class oop{

public:

    oop(int y, int m, int d) : year(y), month(m), date(d) {

    }
    void print() {
        cout << year << "/" << month << "/" << date << '\n';
    }
    void set(int y,int m,int d){
        year = y;
        month = m;
        date = d;
    }

private:
    int year;
    int month;
    int date;
    
};

int main()
{
    
    oop f1(2024,1,10);
    f1.print();

    f1.set(2024,1,11);

    f1.print();
    
    return 0;
}