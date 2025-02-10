#include <iostream>

using namespace std;

int main()
{
    int ways[7500] = { 0 };
    int cents[] = { 1,5,10,25,50 };
    ways[0] = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = cents[i]; j <= 7489; j++)
            ways[j] += ways[j - cents[i]];
    }


    int n;
    while (cin >> n) {
        cout << ways[n] << '\n';
    }
}
