#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, sq;
    while (cin >> a >> b) {
        int count = 0;
        if (!(a + b))
            break;
        for (int i = a; i <= b; i++) {
            sq = floor(sqrt(i));
            if (sq * sq == i)
                count++;
        }
        cout << count << '\n';
    }

    return 0;
}
