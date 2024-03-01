#include <iostream>

using namespace std;

int main()
{
    int n, Case = 0;
    long long int x1, x2, y1, y2, start_x, start_y, end_x, end_y, step;
    cin >> n;
    while (n--) {
        cin >> x1 >> y1 >> x2 >> y2;
        Case++;
        if ((x1 + y1) > (x2 + y2)) {
            start_x = x2;
            start_y = y2;
            end_x = x1;
            end_y = y1;
        }
        else if ((x1 + y1) < (x2 + y2)) {
            start_x = x1;
            start_y = y1;
            end_x = x2;
            end_y = y2;
        }
        else {
            cout << "Case " << Case << ": " << abs(x1 - x2) << '\n';
            continue;
        }
        step = 1;
        step += start_y;
        step += end_x;

        for (int i = start_x + start_y + 1; i < end_x + end_y; i++) {
            step += i+1;
        }
        cout << "Case " << Case << ": " << step << '\n';
    }

    return 0;
}
