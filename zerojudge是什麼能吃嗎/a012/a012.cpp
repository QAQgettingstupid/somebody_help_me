#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    
    long long int a, b;
    
    while (cin >> a) {
        cin >> b;
        cout << abs(a - b) << '\n';
    }

    return 0;
}

