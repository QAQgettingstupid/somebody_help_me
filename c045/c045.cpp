#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> v;
    string s;
    int maxsize=0;
    while (getline(cin, s)) {
        if (s.empty())
            break;
        v.push_back(s);
        if (s.size() > maxsize)
            maxsize = s.size();
    }
    for (int i = 0; i < maxsize; i++) {
        int count = 0, skip = 0;
        while (count < v.size() - 1) {
            if ((v[count]).size()-1 < i)
                skip++;
            else
                break;
            count++;
        }
        for (int j = v.size() - 1; j >= 0; j--) {
            if (v[j].size()-1 >= i) 
                cout << (v[j])[i];
            else if (j > skip - 1)
                cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}