#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    //input 0 會炸裂QAQ
    int num;
    string s;
    vector<int> v;
    while (getline(cin, s)) {
        int Max = 0, sum = 0;
        for (int i=0; i < s.size(); i++) {
            if (s[i] <= '9' && s[i] >= '0') {
                num = s[i] - '0';
            }
            else if (s[i] <= 'Z' && s[i] >= 'A') {
                num = s[i] - 'A' + 10;
            }
            else if (s[i] <= 'z' && s[i] >= 'a') {
                num = s[i] - 'a' + 36;
            }
            else
                continue;
            v.push_back(num);
            Max = max(Max, num);
            sum += num;
        }
        if (v.size() == 1 && v[0] == 0)
            cout << 2 << '\n';
        else {
            int i;
            for (i = Max; i < 62; i++) {
                if (sum % i == 0) {
                    cout << i + 1 << '\n';
                    break;
                }
                else
                    continue;
            }
            if (i == 62)
                cout << "such number is impossible!\n";
        }
        v.clear();
    }

    return 0;
}

