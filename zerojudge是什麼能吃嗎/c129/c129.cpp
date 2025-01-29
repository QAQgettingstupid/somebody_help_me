#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main()
{
    int m, n, ans;
    char ground[110][110];
    queue<pair<int, int>> oil;
    set<pair<int, int>> oil_place;
    while (cin >> m >> n) {
        if (!(m + n))
            break;

        //初始化
        ans = 0;
        for(int i=1;i<=m;i++)
            for (int j = 1; j <= n; j++) {
                cin >> ground[i][j];
                if (ground[i][j] == '@')
                    oil_place.insert(make_pair(m, n));
            }

        //disconnected graph 反覆遍歷
        while (!oil_place.empty()) {
            
            //BFS
            oil.push(*oil_place.begin());
            oil_place.erase(oil_place.begin());
            while (!oil.empty()) {

                //上
                if(oil_place.count(make_pair())
            }
            ans++;
        }

        cout << ans << "\n";
    }
}
