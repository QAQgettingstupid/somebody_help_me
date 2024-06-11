#include <iostream>

using namespace std;

int main()
{
    int high[100010] = { 0 };
    int left,right,tall,end = 0;
    while (cin >> left >> tall >> right) {
        if (!(left + tall + right))
            break;
        if (right > end)
            end = right;
        for (int i = left; i <= right; i++) {
            if (tall > high[i])
                high[i] = tall;
        }
    }
    //印出來的順序怪怪的
    int front = high[1];
    cout << 1 << " " << high[1] << " ";
    for (int i = 2; i <= end; i++) {
        if (high[i] != front) {
            front = high[i];
            if(!high[i])
                cout << i-1 << " " << high[i] << " ";
            else
                cout << i << " " << high[i] << " ";
        }
    }
    cout << end << " " << 0;
    return 0;
}
