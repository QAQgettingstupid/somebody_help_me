#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, m,count=1;
    string s;
    while (cin >> n >> m) {
        if (n + m == 0)
            break;
        char map[105][105];
        for (int i = 0; i < 105; i++) {
            for (int j = 0; j < 105; j++)
                map[i][j] = '0';
        }
        getline(cin, s);
        for (int i = 0; i < n; i++) {
            getline(cin, s);
            for(int j=0;j<s.size();j++)
                if (s[j] == '*') {
                    map[i+1][j+1] = '9';

                    //周圍8個
                    map[i][j]++;
                    map[i][j + 1]++;
                    map[i][j + 2]++;
                    map[i + 1][j]++;
                    map[i + 1][j + 2]++;
                    map[i + 2][j]++;
                    map[i + 2][j + 1]++;
                    map[i + 2][j + 2]++;
                }
        }
        cout << "Field #" << count << ":\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (map[i][j] >= '9')
                    cout << "*";
                else
                    cout << map[i][j];
            }
            cout << '\n';
        }
        count++;
    }

    return 0;
}

