#include <iostream>

using namespace std;

int main()
{
    long long int t, n, count = 1;
    string s;
    cin >> t;
    while (t--) {
        bool flag = true;
        long long int sqr[100][100];
        cin >> s >> s >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> sqr[i][j];
                if (sqr[i][j] < 0)
                    flag = false;
            }
        }
        if (flag) {
            for (int i = 0; i <= n / 2; i++) {
                for (int j = 0; j < n; j++)
                    if (sqr[i][j] != sqr[n - 1 - i][n - 1 - j])
                        flag = false;
            }
        }
        cout << "Test #" << count << ": ";
        if (flag)
            cout << "Symmetric.\n";
        else
            cout << "Non-symmetric.\n";
        count++;
    }

    return 0;
}
