#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int n;
    map<string, int> country;
    string need, s;
    cin >> n;
    getline(cin, s);
    while (n--) {
        cin >> need;
        getline(cin, s);
        country[need]++;
    }
    for (auto it : country)
        cout << it.first << " " << it.second << '\n';
    return 0;
}

