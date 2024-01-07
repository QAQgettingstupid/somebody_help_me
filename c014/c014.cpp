#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string up, down;
    while (cin >> up) {
        cin >> down;
        int count = 0, carry = 0, num[3][11] = { 0 };
        if (up == down && down == "0")
            break;
        for (int i = 0; i < up.size(); i++) {
            num[0][i] = up[up.size() - 1 - i] - '0';
        }
        for (int i = 0; i < down.size(); i++) {
            num[1][i] = down[down.size() - 1 - i] - '0';
        }
        int i = 0,add;
        while (num[0][i] || num[1][i] || i<max(up.size(),down.size())) {
            add = num[0][i] + num[1][i] + carry;
            if (add >= 10) {
                count++;
                carry = 1;
            }
            else
                carry = 0;
            i++;
        }
        if (count > 1)
            cout << count << " carry operations.\n";
        else if (count)
            cout << "1 carry operation.\n";
        else
            cout << "No carry operation.\n";

    }

    return 0;
}

