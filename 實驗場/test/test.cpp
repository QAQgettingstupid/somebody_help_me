#include <iostream>

using namespace std;

int main()
{
    int a[10];
    a[5] = 55;
    int* p = new int[50];
    int* b[10];
    b[0] = &a[5];
    p[5] = a[5];
    cout << p[5]<<'\n';
    cout << *b[0] << '\n';
    a[5] = 65;
    cout << p[5] << '\n';
    cout << *b[0] << '\n';
    return 0;
}
