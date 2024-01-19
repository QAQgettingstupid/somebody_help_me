#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n,num,mid1,mid2;
    vector<int> v;
    while (cin >> n) {
        mid2 = 0;
        for (int i = 0; i < n; i++) {
            cin >> num;
            v.push_back(num);
        }
        sort(v.begin(), v.end());
        if (n % 2)
            mid1 = v[n / 2];
        else {
            mid1 = v[(n / 2) - 1];
            mid2 = v[n / 2];
        }
        cout << mid1 << " ";

        int count = 0;
        for (int i = 0; i < v.size(); i++)
            if (v[i] == mid1 || v[i] == mid2)
                count++;
        cout << count << " ";
        if (mid2)
            cout << mid2 - mid1 + 1 << '\n';
        else
            cout << 1 << '\n';

        v.clear();
    }

    return 0;
}
