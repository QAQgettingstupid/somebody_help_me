#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

int main() 
{
    vector<pair<double, double>> stone;
    int n, count = 0;
    double x, y, Max, distance;
    while (cin >> n) {
        if (n == 0)
            break;
        count++;

        //頭尾
        stone.clear();
        for (int i = 0; i < 2; i++) {
            cin >> x >> y;
            stone.push_back(make_pair(x, y));
        }

        if(n==2)
            Max = sqrt(pow((stone[1].first - stone[0].first), 2) + pow((stone[1].second - stone[0].second), 2));
        
        else {

            for (int i = 0; i < n - 2; i++) {
                cin >> x >> y;
                stone.push_back(make_pair(x, y));
            }

            vector<vector<double>> min_distance(n, vector<double>(n));

            for(int i=0;i<n;i++)
                for (int j = 0; j < n; j++) {
                    min_distance[i][j] = sqrt(pow((stone[i].first - stone[j].first), 2) + pow((stone[i].second - stone[j].second), 2));
                }

            // Floyd-Warshall algorithm -->把原本存最短路徑條件改為存跳躍距離最小值
            for(int k=0;k<n;k++)
                for(int i=0;i<n;i++)
                    for (int j = 0; j < n; j++) {
                        min_distance[i][j] = min(min_distance[i][j], max(min_distance[i][k], min_distance[k][j]));
                    }

            Max = min_distance[0][1];
        }

        cout << "Scenario #";
        cout << count << '\n';
        cout << "Frog Distance = " << fixed << setprecision(3) << Max << '\n';
        cout << '\n';
    }

    return 0;
}

