#include <iostream>

using namespace std;

int main()
{
    long long int  D, day, S;
    while (cin >> S >> D) {
        day = 0;
        while (1) {
            if (D <= day + S) {
                cout << S << '\n';
                break;
            }
            day += S;
            S++;
        }
        
    }

    return 0;
}