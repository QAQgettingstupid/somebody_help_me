#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

int main()
{
    int n;
    double sum;
    string s;
    map<string, double> mp;
    cin >> n;
    getline(cin, s);
    getline(cin, s);
    while (n--) {
        sum = 0;
        do {
            getline(cin, s);
            if (s != ""){
               sum++;
               mp[s]++;
            }
        } while (s != "");
        for (auto it : mp)
            cout << fixed << setprecision(4) << it.first << " " << (it.second) / sum*100 << '\n';
        mp.clear();
    }

    return 0;
}
