#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void print(int n, string* num) {
    string ans = num[n];
    reverse(ans.begin(), ans.end());
    cout << "The Fibonacci number for " << n << " is " << ans << '\n';
}

int main()
{
    string num[5010];
    num[0] = "0";
    num[1] = "1";
    int n, length, carry, now, index;

    for (int i = 2; i <= 5000; i++) { 
        length = num[i - 2].size();
        carry = 0;
        for (index = 0; index < length; index++) { //字串大數加法
            now = (num[i - 1][index] + num[i - 2][index] - 2 * '0') + carry;
            carry = now / 10;
            num[i] += to_string(now % 10);
        }
        while (carry && index < num[i - 1].size()) {
            now = (num[i - 1][index] - '0') + carry;
            carry = now / 10;
            num[i] += to_string(now % 10);
            index++;
        }
        if (index < num[i - 1].size()) {
            string left = num[i - 1].substr(index);
            num[i] += left;
        }
        if (carry) {
            num[i] += to_string(carry);
        }
    }

    while (cin >> n) {
        print(n, num);
    }

    return 0;
}