#include <iostream>

using namespace std;

int main()
{
    int king, queen, new_queen;
    while (cin >> king >> queen >> new_queen) {
        
        if (king == queen) {
            cout << "Illegal state\n";
            continue;
        }

        if (new_queen == queen) {
            cout << "Illegal move\n";
            continue;
        }

        if(new_queen % 8 == queen % 8 &&(new_queen>king || new_queen < king))

        if (new_queen % 8 != queen % 8 && (new_queen - (queen - queen % 8) < 0 || new_queen - (queen - queen % 8) > 7)) {
            cout << "Illegal move\n";
            continue;
        }

        if (new_queen == king - 8 || new_queen < king) { //上
            cout << "Move not allowed\n";
            continue;
        }

        if (new_queen == king + 8 || new_queen > king) { //下
            cout << "Move not allowed\n";
            continue;
        }

        if (king % 8 != 0 && new_queen == king - 1) { //左
            cout << "Move not allowed\n";
            continue;
        }

        if (king % 8 != 7 && new_queen == king + 1) { //右
            cout << "Move not allowed\n";
            continue;
        }
    }

    return 0;
}
