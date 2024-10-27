#include <iostream>
using namespace std;

int add5(int* a) {

    *a += 5;

    int b = 99;
    
    return b + 1;
}

int main() {
    int A = 1;

    add5(&A);
    cout << A;


    return 0;
}