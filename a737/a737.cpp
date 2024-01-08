#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, house, r;
    int s[510];
    cin >> n;
    while (n--) {
        cin >> r;
        int sum = 0;
        for (int i = 0; i < r; i++)
            cin >> s[i];
        sort(s, s + r);
        house = s[(r-1) / 2];
        for (int i = 0; i < r; i++)
            sum += abs(house - s[i]);
        cout << sum << '\n';
    }
    return 0;
}