#include <iostream>

using namespace std;

int main()
{
    int high[100010] = { 0 };
    int left,right,tall,end = 0;
    while (cin >> left >> tall >> right) {
        if (right > end)
            end = right;
        for (int i = left; i < right; i++) {
            if (tall > high[i])
                high[i] = tall;
        }
    }

    //印出來的順序怪怪的
    int front = 0;
    while (!high[front]) {
        front++;
    }
    cout << front << " " << high[front] << " ";
    for (int i = front + 1; i < end; i++) {
        if (high[i] != high[front]) {
            high[front] = high[i];
            cout << i << " " << high[i] << " ";
        }
    }
    cout << end << " " << 0;
    return 0;
}
