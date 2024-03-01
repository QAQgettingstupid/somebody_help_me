#include <iostream>

using namespace std;

int main()
{
    int n, s, d,big,small;
    cin >> n;
    while (n--) {
        cin >> s >> d;
        if (d > s || (s - d) % 2)
            cout << "impossible\n";
        else {
            big = (s - d) / 2 + d;
            small = (s - d) / 2;
            cout << big << " " << small << '\n';
        }
    }

    return 0;
}
