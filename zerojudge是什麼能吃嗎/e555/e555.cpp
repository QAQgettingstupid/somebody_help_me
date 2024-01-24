#include <iostream>

using namespace std;

int main()
{
    long long int  D, day, S;
    while (cin >> S >> D) {
        day = 0;
        do {
            for (int i = 0; i < S; i++)
                day++;
        } while (day < D);
        
    }

    return 0;
}