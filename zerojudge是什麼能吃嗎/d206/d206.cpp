#include <iostream>

using namespace std;

int main()
{
    int n;
    long long int ans, sum, square[101][101] = { 0 };
    while (cin >> n) {

        //輸入
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> square[i][j];
                square[i][j] += square[i][j - 1];
            }
        }
        ans = square[1][1];
        //尋找
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j <= n; j++) {
                sum = 0;
                for (int h = 1; h <= n; h++) {
                    if (sum<0 && sum < (square[h][j] - square[h][i])) //反正前面已經小於0乾脆別算,重新開始
                        sum = 0;
                    sum += square[h][j] - square[h][i];
                    ans = max(ans, sum);
                }
            }

        cout << ans << "\n";
    }
    return 0;
}

