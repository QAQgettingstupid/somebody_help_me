#include <iostream>
#include <iomanip>
#include <cmath>
#define pi acos(0.0)*2.0
using namespace std;

int main()
{
    double s, a,ansc,ansa;
    string unit;
    while (cin >> s >> a >> unit) {
        if (unit == "min")
            a /= 60;
        if (a > 180)
            a = 360 - a;
        ansc = (s + 6440) * (a / 180) * pi;
        ansa = sqrt((2 * (s + 6440) * (s + 6440)) - (2 * (s + 6440) * (s + 6440) * cos((a / 180) * pi)));
        //弧長
        cout << fixed << setprecision(6) << ansc << " ";
        //弦長
        cout << ansa << '\n';
    }

    return 0;
}
