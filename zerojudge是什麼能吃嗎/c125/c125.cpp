#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

int main() //距離怪怪的雖然不確定原因
{
    vector<pair<double, double>> stone;
    int n, count = 0;
    double x, y, Max, distance;
    while (cin >> n) {
        if (n == 0)
            break;
        count++;
        Max = 0;
        stone.clear();
        for (int i = 0; i < 2; i++) {
            cin >> x >> y;
            stone.push_back(make_pair(x, y));
        }
        if(n==2)
            Max = sqrt(pow((stone[1].first - stone[0].first), 2) + pow((stone[1].second - stone[0].second), 2));
        for (int i = 0; i < n - 2; i++) {
            cin >> x >> y;
            for (int j = 0; j < stone.size(); j++) {
                distance = sqrt(pow((stone[j].first - x), 2) + pow((stone[j].second - y), 2));
                Max = max(Max, distance);
            }
        }
        cout << "Scenario #";
        cout << count << '\n';
        cout << "Frog Distance = " << fixed << setprecision(3) << Max << '\n';
    }

    return 0;
}

