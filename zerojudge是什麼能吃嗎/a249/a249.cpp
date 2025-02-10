#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, D, I, ans;
    cin >> n;
    while (n--) {
        ans = 1;
        cin >> D >> I;

        //計算--> 球編號-1後轉二進位恰好為路徑, 1 -> 向右, 0 -> 向左
        I--;
        while (D > 1) {
            if (I % 2)
                ans = ans * 2 + 1;
            else
                ans *= 2;
            I >>= 1;
            D--;
        }

        cout << ans << '\n';
    }
}
