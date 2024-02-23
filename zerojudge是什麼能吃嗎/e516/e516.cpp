#include <iostream>

using namespace std;

int main()
{
    int n;
    string s;
    while (cin >> n) {
        if (!n)
            break;
        int top=1, right=4, front=2,temp;
        while (n--) {
            cin >> s;
            if (s == "east") {
                temp = right;
                right = top;
                top = 7-temp;
            }
            else if (s == "south") {
                temp = front;
                front = 7 - top;
                top = temp;
            }
            else if (s == "west") {
                temp = right;
                right = 7 - top;
                top = temp;
            }
            else {
                temp = front;
                front = top;
                top = 7 - temp;
            }
        }
        cout << top << '\n';
    }
    

    return 0;
}
