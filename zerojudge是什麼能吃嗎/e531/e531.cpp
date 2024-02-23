#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int t;
    string s;
    map<char, vector<int>> note;
    note['c'] = { 0,0,1,1,1,0,0,1,1,1,1 };
    note['d'] = { 0,0,1,1,1,0,0,1,1,1,0 };
    note['e'] = { 0,0,1,1,1,0,0,1,1,0,0 };
    note['f'] = { 0,0,1,1,1,0,0,1,0,0,0 };
    note['g'] = { 0,0,1,1,1,0,0,0,0,0,0 };
    note['a'] = { 0,0,1,1,0,0,0,0,0,0,0 };
    note['b'] = { 0,0,1,0,0,0,0,0,0,0,0 };
    note['C'] = { 0,0,0,1,0,0,0,0,0,0,0 };
    note['D'] = { 0,1,1,1,1,0,0,1,1,1,0 };
    note['E'] = { 0,1,1,1,1,0,0,1,1,1,0 };
    note['F'] = { 0,1,1,1,1,0,0,1,0,0,0 };
    note['G'] = { 0,1,1,1,1,0,0,0,0,0,0 };
    note['A'] = { 0,1,1,1,0,0,0,0,0,0,0 };
    note['B'] = { 0,1,1,0,0,0,0,0,0,0,0 };

    cin >> t;
    getline(cin, s);

    while (t--) {
        getline(cin, s);
        int hand[11] = { 0 },count[11] = { 0 };
        for (int i = 0; i < s.size(); i++) {
            for (int j = 1; j <= 10; j++) {
                if (note[s[i]][j] > hand[j]) {
                    count[j]++;
                    hand[j] = 1;
                }
                else if (note[s[i]][j] < hand[j])
                    hand[j] = 0;
            }
        }
        cout << count[1];
        for (int i = 2; i <= 10; i++)
            cout << " " << count[i];
        cout << '\n';

    }

    return 0;
}
