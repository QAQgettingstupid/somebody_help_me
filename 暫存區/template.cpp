#include <iostream>

using namespace std;

template<class t>
void sort(t a, int size) {
    cout << a;
}

int main()
{
    sort<string>("5.5", 5); // �I�s-> sort<���A>(���A, 5);
    return 0;
}
