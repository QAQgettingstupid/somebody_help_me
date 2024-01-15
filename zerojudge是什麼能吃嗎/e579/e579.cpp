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
        int count = 0;
        if (v[0] == 1) {
            count = N - (N / 7 * 2);
            if (N % 7 == 6)
                count--;
            cout << count << '\n';
        }
        //削減因數
        else {
            for (int j = v.size() - 1; j > 0; j--) {
                for (int k = j-1; k >= 0; k--) {
                    if (!(v[j] % v[k])) {
                        v.erase(v.begin() + j);
                        break;
                    }
                }
            }
            //消完了QAQ
            for (int j = 0; j < v.size(); j++) {
                int now = v[j];
                while (now <= N) {
                    if ((now + 1) % 7 != 0 && now % 7 != 0)
                        st.insert(now);
                    now += v[j];
                }
            }
            cout << st.size() << '\n';
            st.clear();
        }
        v.clear();
    }

    return 0;
}

