#include <iostream>
#include <iomanip>

#define INF 1e9

using namespace std;

struct Line {
    double x1, x2, y1, y2;
    double m, b;//b -> y截距
};

void write_line(Line& line) {

    if (line.x1 == line.x2) {
        line.m = INF;
        line.b = INF;
    }
    else {
        line.m = (line.y2 - line.y1) / (line.x2 - line.x1);
        line.b = line.y1 - line.m * line.x1;
    }
}

int main()
{
    int N;
    double point_x, point_y;
    Line l1, l2, l3;
    cout << "INTERSECTING LINES OUTPUT\n";
    cin >> N;

    while (N--) { 

        cin >> l1.x1 >> l1.y1 >> l1.x2 >> l1.y2 >> l2.x1 >> l2.y1 >> l2.x2 >> l2.y2;

        l3.x1 = l1.x1;
        l3.x2 = l2.x1;
        l3.y1 = l1.y1;
        l3.y2 = l2.y1;
        write_line(l1);
        write_line(l2);
        write_line(l3);

        if (l1.m == l2.m && l1.m == l3.m)
            cout << "LINE\n";
        else if (l1.m == l2.m)
            cout << "NONE\n";
        else {
            if (l1.m == 0 && l2.m== INF) {
                point_x = l2.x1;
                point_y = l1.y1;
            }
            else if (l2.m == 0 && l1.m == INF) {
                point_x = l1.x1;
                point_y = l2.y1;
            }
            else if (l1.m == INF) {
                point_x = l1.x1;
                point_y = l2.y1 + (l1.x1 - l2.x1) * l2.m;
            }
            else if (l2.m == INF) {
                point_x = l2.x1;
                point_y = l1.y1 + (l2.x1 - l1.x1) * l1.m;
            }
            else {
                point_x = -(l2.b - l1.b) / (l2.m - l1.m);
                point_y = l1.m * point_x + l1.b;
            }
            cout << "POINT " << fixed << setprecision(2) << point_x << " " << setprecision(2) << point_y << '\n';
        }
    }
    cout << "END OF OUTPUT\n";

    return 0;
}

