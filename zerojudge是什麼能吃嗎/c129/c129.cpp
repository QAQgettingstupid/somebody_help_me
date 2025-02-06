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
                    oil_place.insert(make_pair(i, j));
            }

        
        /*pair<int, int> i;
        for (auto i : oil_place)
            cout << i.first << " " << i.second << "\n";*/

        //disconnected graph 反覆遍歷
        while (!oil_place.empty()) {
            
            //BFS
            oil.push(*oil_place.begin());
            oil_place.erase(oil_place.begin());
            int size = 0;
            while (!oil.empty()) {

                //上
                if (oil_place.count(make_pair(oil.front().first, oil.front().second + 1)))
                    oil.push(make_pair(oil.front().first, oil.front().second + 1));

                //下
                if (oil_place.count(make_pair(oil.front().first, oil.front().second - 1)))
                    oil.push(make_pair(oil.front().first, oil.front().second - 1));

                //左
                if (oil_place.count(make_pair(oil.front().first - 1, oil.front().second)))
                    oil.push(make_pair(oil.front().first - 1, oil.front().second));

                //右
                if (oil_place.count(make_pair(oil.front().first + 1, oil.front().second)))
                    oil.push(make_pair(oil.front().first + 1, oil.front().second));

                //右上
                if (oil_place.count(make_pair(oil.front().first + 1, oil.front().second + 1)))
                    oil.push(make_pair(oil.front().first + 1, oil.front().second + 1));

                //右下
                if (oil_place.count(make_pair(oil.front().first + 1, oil.front().second - 1)))
                    oil.push(make_pair(oil.front().first + 1, oil.front().second - 1));

                //左上
                if (oil_place.count(make_pair(oil.front().first - 1, oil.front().second + 1)))
                    oil.push(make_pair(oil.front().first - 1, oil.front().second + 1));

                //左下
                if (oil_place.count(make_pair(oil.front().first - 1, oil.front().second - 1)))
                    oil.push(make_pair(oil.front().first - 1, oil.front().second - 1));

                size++;
                oil_place.erase(oil.front());
                oil.pop();
            }
            if (size)
                ans++;
        }

        cout << ans << "\n";
    }
}
