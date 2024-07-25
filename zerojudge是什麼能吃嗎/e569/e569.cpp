#include <iostream>
#include <cctype>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector <string> list;
    string s, temp;
    string word = "";
    int num = 0;
    while (getline(cin, s)) {
        if (s == "0")
            break;
        for (int i = 0; i < s.size(); i++) {

            if (isalpha(s[i])) {
                word += s[i];
            }
            else if (isdigit(s[i])) {
                num *= 10;
                num += s[i]-'0';
            }
            else {
                if (word != "") {
                    list.push_back(word);
                    cout << word;
                    word = "";
                }
                if (num) {
                    cout << *(list.end() - num);
                    temp = *(list.end() - num);
                    if (num > 1) {
                        list.push_back(temp);
                        for (auto it = list.begin(); it < list.end(); it++) {
                            if (*it == temp) {
                                list.erase(it);
                                break;
                            }
                        }
                    }
                    num = 0;
                }
                cout << s[i];
            }
        }
        if (word != "") {
            list.push_back(word);
            cout << word;
            word = "";
        }
        if (num) {
            cout << *(list.end() - num);
            temp = *(list.end() - num);
            if (num > 1) {
                list.push_back(temp);
                for (auto it = list.begin(); it < list.end(); it++) {
                    if (*it == temp) {
                        list.erase(it);
                        break;
                    }
                }
            }
            num = 0;
        }
        cout << '\n';
    }
    return 0;
}

