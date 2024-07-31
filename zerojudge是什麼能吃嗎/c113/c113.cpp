#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int N;
    double x1, x2, x3, x4, y1, y2, y3, y4;
    double m1, m2, m3, b1, b2; //b -> y截距
    cout << "INTERSECTING LINES OUTPUT\n";
    cin >> N;

    while (N--) { //鉛垂線斜率會出事,待修www
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        m1 = (y2 - y1) / (x2 - x1);
        m2 = (y4 - y3) / (x4 - x3);
        m3 = (y2 - y1) / (x4 - x3);
        if (m1 == m2 && m1 == m3)
            cout << "LINE\n";
        else if (m1 == m2)
            cout << "NONE\n";
        else {
            double point_x, point_y;
            b1 = y1 + (-x1) * 3;
            b2 = y3 + (-x3) * 3;
            point_x = -(b2 - b1) / (m2 - m1);
            point_y = m1 * point_x + b1;
            cout << "POINT " << fixed << setprecision(2) << point_x << " " << setprecision(2) << point_y << '\n';
        }
    }
    cout << "END OF OUTPUT\n";

    return 0;
}

