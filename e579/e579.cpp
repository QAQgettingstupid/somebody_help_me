#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int T, N, P, i;
    vector<int> v;
    set<int> st;
    cin >> T;
    while (T--) {
        cin >> N >> P;
        for (int j = 0; j < P; j++) {
            cin >> i;
            v.push_back(i);
        }
        sort(v.begin(), v.end());
        if (v[0] == 1)
            cout << N << '\n';
        //削減因數
        else {
            for (int j = v.size() - 1; j > 0; j--) {
                for (int k = j; k >= 0; k--) {
                    if (!(v[j] % v[k])) {
                        v.erase(v.begin() + j);
                        break;
                    }
                }
            }
            //消完了QAQ
        }
    }

    return 0;
}

