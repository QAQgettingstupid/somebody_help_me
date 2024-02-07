#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int x,ans;
    string s,an;
    vector<int> num;
    while (cin >> x) {
        ans = 0;
        getline(cin, s);
        getline(cin, s);
        stringstream ss(s);
        while (ss >> an)
            num.push_back(stoi(an));
        reverse(num.begin(), num.end());
        if (num.size() > 1)
            for (int i = 1; i < num.size(); i++) {
                num[i - 1] = num[i] * i;
                ans += num[i - 1] * pow(x, i - 1);
            }
        else
            ans = 0;
        cout << ans << '\n';
        num.clear();
    }

    return 0;
}

