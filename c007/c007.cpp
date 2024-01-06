#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    bool t = 0;
    while (getline(cin, s)) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '"')
                if (!t) {
                    s[i] = '`';
                    s.insert(s.begin() + i, '`');
                    t = 1-t;
                }
                else {
                    s[i] = '\'';
                    s.insert(s.begin() + i, '\'');
                    t = 1 - t;
                }
        }
        cout << s << '\n';
    }
    return 0;
}
