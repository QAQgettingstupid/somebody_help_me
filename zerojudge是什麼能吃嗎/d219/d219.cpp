#include <iostream>

using namespace std;

int main()
{
    long long int B, P, M, base, ans;

    while (cin >> B >> P >> M) {//快速幕&mod運算
        ans = 1;
        base = B % M;
        while (P) {
            if (P % 2) {
                ans = (ans * base) % M;
            }
            P /= 2;
            base = (base * base) % M;
        }
        cout << ans << '\n';
    }

    return 0;
}

