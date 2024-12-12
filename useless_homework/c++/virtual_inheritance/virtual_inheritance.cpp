#include <iostream>

using namespace std;

class A {
protected:
    int a;
public:
    A() {
        a = 6;
    }
};

class B :virtual public A {
public:
    void writea(int x);
    int reada();
};

class C :virtual public A {

};

class D :public B, public C {

};

void B::writea(int x) {
    a = x;
}

int B::reada() {
    return a;
}

int main()
{
    D x;
    cout << x.reada() << '\n';
    x.writea(5);
    cout << x.reada() << '\n';

    return 0;
}

