#include <iostream>

using namespace std;

int main()
{
    int T, month, date, ans;
    int doom[12] = { 10,21,7,4,9,6,11,8,5,10,7,12 };
    string day[7] = { "Monday\n","Tuesday\n","Wednesday\n","Thursday\n","Friday\n","Saturday\n","Sunday\n" };
    cin >> T;
    while (T--) {
        cin >> month >> date;
        ans = (date - doom[month - 1]) % 7;
        if (ans >= 0)
            cout << day[ans];
        else
            cout << day[ans + 7];
    }

    return 0;
}