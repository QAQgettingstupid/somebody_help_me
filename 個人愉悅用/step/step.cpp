#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int a[5][5];
    int x, y;
    stack<int> s;
    while (cin >> x >> y) {
        if (!x || !y)
            break;
        a[x][y] = 1;
    }



    return 0;
}

