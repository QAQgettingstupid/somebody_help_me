#include <iostream>

using namespace std;

int main()
{
    int Min;
    string s1, s2;
    while (cin >> s1 >> s2) {
        int abc[2][26] = { 0 };
        for (int i = 0; i < s1.size(); i++)
            abc[0][s1[i]-'a']++;
        for (int i = 0; i < s2.size(); i++)
            abc[1][s2[i] - 'a']++;
        for (int i = 0; i < 26; i++) {
            Min = min(abc[0][i], abc[1][i]);
            for (int j = 0; j < Min; j++) {
                char ans = 'a';
                ans += i;
                cout << ans;
            }
        }
        cout << '\n';
    }

    return 0;
}

