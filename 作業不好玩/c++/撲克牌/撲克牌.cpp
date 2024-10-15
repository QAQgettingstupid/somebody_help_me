#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int card, point, type, used[53] = { 0 };
    for (int i = 0; i < 10; i++) {
        do {
            card = rand() % 52 + 1;
        } while (used[card]);
        used[card] = 1;
        point = card % 13 + 1;
        type = card % 4;
        switch (type) {
        case 0:
            cout << "club ";
            break;
        case 1:
            cout << "heart ";
            break;
        case 2:
            cout << "diamond ";
            break;
        case 3:
            cout << "spade ";
            break;
        }
        cout << point << '\n';
    }
    return 0;
}