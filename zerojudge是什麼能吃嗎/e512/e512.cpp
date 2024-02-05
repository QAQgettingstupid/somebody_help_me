#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double x0, x1, x2, x3, x4, y0, y1, y2, y3, y4;
    while (cin >> x0 >> y0) {
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        cin >> x3 >> y3;
        if (x0 == x2 && y0 == y2) {
            x1 += x3;
            y1 += y3;
            x4 = x1 - x0;
            y4 = y1 - y0;
        }
        else if (x0 == x3 && y0 == y3) {
            x1 += x2;
            y1 += y2;
            x4 = x1 - x0;
            y4 = y1 - y0;
        }
        else if (x1 == x3 && y1 == y3) {
            x0 += x2;
            y0 += y2;
            x4 = x0 - x1;
            y4 = y0 - y1;
        }
        else if (x1 == x2 && y1 == y2) {
            x0 += x3;
            y0 += y3;
            x4 = x0 - x1;
            y4 = y0 - y1;
        }
        cout << fixed << setprecision(3) << x4 << " " << y4 << '\n';
    }
    return 0;
}

