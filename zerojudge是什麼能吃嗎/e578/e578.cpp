#include <iostream>
#include <string>
#include <map>

using namespace std;



int main()
{
    string s[4] = {
        "`1234567890-=",
        "qwertyuiop[]\\",
        "asdfghjkl;'",
        "zxcvbnm,./"
    };
    map<char, char> mp;
    for (int i = 0; i < 4; i++) {
        for (int j = s[i].size() - 1; j > 1; j--)
            mp[s[i][j]] = s[i][j - 2];
    }
    string s1;
    while (getline(cin, s1)) {
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == ' ')
                cout << " ";
            else
                cout << mp[s1[i]];
        }
        cout << '\n';
    }
    return 0;
}