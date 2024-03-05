#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T,M,N,Q,r,c,count; // M->高度 N->寬度
    string s;
    cin >> T;
    while (T--) {
        char map[100][100];
        cin >> M >> N >> Q;
        for (int i = 0; i < M; i++) { //塞地圖
            cin >> s;
            for (int j = 0; j < N; j++)
                map[i][j] = s[j];
        }
        cout << M << " " << N << " " << Q << '\n';
        while (Q--) { //挖地圖
            cin >> r >> c;
            bool flag=true;
            count = 0;
            while (1) {
                for (int i = r - (count + 1); i <= r + (count + 1); i++) {
                    for (int j = c - (count + 1); j <= c + (count + 1); j++)
                        if (i<0 || i>(M - 1) || j < 0 || j>(N - 1) || (map[i][j] != map[r][c])) {
                            flag = false;
                            break;
                        }
                    if (!flag)
                        break;
                }
                if (flag)
                    count++;
                else
                    break;
            }
            cout << 1 + count * 2 << '\n';
        }
    }

    return 0;
}

