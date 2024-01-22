#include <iostream>
#include <string>

using namespace std;

void print(int a) {

    if (a / 10000000) {
        cout << a / 10000000 << " kuti ";
        a = a % 10000000;
    }

    if (a / 100000) {
        cout << a / 100000 << " lakh ";
        a = a % 100000;
    }

    if (a / 1000) {
        cout << a / 1000 << " hajar ";
        a = a % 1000;
    }

    if (a / 100){
        cout << a / 100 << " shata ";
        a = a % 100;
    }
    if (a)
        cout << a;
}

int main()
{
    int count = 1,front,back;
    long long int num;
    string s;
    while (cin >> s) {
        cout <<"   " << count << ". ";
        num = stoll(s);
        if (!num) {
            cout << 0 << '\n';
            count++;
            continue;
        }
        front = num / 10000000;
        back = num % 10000000;
        print(front);
        if (front && front % 100)
            cout << " kuti ";
        else if(front)
            cout << "kuti ";
        print(back);
        cout << '\n';
        count++;
    }

    return 0;
}
