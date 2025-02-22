#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    int graph[110][110] = {0};
    int T, x, y, row, column, size;
    string s;
    queue<pair<int, int>> water;
    cin >> T;
    while (T--) {
        cin >> y >> x;
		getline(cin, s);//讀掉換行符號
        getline(cin, s);
        size = 0;
        row = 1;
        column = s.size();

        while (1) {
            for (int i = 1; i <= column; i++)
                graph[row][i] = s[i - 1] - '0';
            getline(cin, s);
            if (s.empty())
                break;
            else
                row++;
        }

        //BFS
        water.push(make_pair(y, x));
        while (!water.empty()) {

            if (!graph[water.front().first][water.front().second]) {
                
                graph[water.front().first][water.front().second] = 1;

                //下
                if (water.front().first + 1 <= row && !graph[water.front().first + 1][water.front().second])
                    water.push(make_pair(water.front().first + 1, water.front().second));
                //上
                if (water.front().first - 1 > 0 && !graph[water.front().first - 1][water.front().second])
                    water.push(make_pair(water.front().first - 1, water.front().second));
                //右
                if (water.front().second + 1 <= column && !graph[water.front().first][water.front().second + 1])
                    water.push(make_pair(water.front().first, water.front().second + 1));
                //左
                if (water.front().second - 1 > 0 && !graph[water.front().first][water.front().second - 1])
                    water.push(make_pair(water.front().first, water.front().second - 1));
                size++;
            }
            water.pop();
        }
        if (T > 0)
            cout << size << "\n\n";
        else
            cout << size << '\n';
    }
}
