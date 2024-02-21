#include <iostream>

using namespace std;

int main()
{
    int n,step,top;//east->0 south->1 west->2 north->3
    int dice[7][4] = { 0,0,0,0,
                       3,2,4,5,
                       3,6,4,1,
                       6,2,1,5,
                       1,2,6,5,
                       3,1,4,6,
                       3,5,4,2, };
    string s;
    while (cin >> n) {
        if (!n)
            break;
        top = 1;
        while (n--) {
            cin >> s;
            if (s == "east")
                step = 0;
            else if(s == "south")
                step = 1;
            else if(s == "west")
                step = 2;
            else
                step = 3;
            top = dice[top][step];
            cout << top;
        }
        cout << top << '\n';
    }
    

    return 0;
}
