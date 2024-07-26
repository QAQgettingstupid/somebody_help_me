#include <iostream>

using namespace std;

int main()
{
    int king, queen, new_queen, king_x, king_y, queen_x, queen_y, new_queen_x, new_queen_y;
    
    while (cin >> king >> queen >> new_queen) {

        if (king == queen) {
            cout << "Illegal state\n";
            continue;
        }

        if (new_queen == queen || new_queen == king) {
            cout << "Illegal move\n";
            continue;
        }

        king_x = king % 8;
        king_y = king - king % 8;
        queen_x = queen % 8;
        queen_y = queen - queen % 8;
        new_queen_x = new_queen % 8;
        new_queen_y = new_queen - new_queen % 8;


        if (new_queen_x != queen_x && new_queen_y != queen_y) {
            cout << "Illegal move\n";
            continue;
        }

        if (queen_x == king_x) {
            if (queen_y > king_y && king_y > new_queen_y) {
                cout << "Illegal move\n";
                continue;
            }
            else if (queen_y < king_y && king_y < new_queen_y) {
                cout << "Illegal move\n";
                continue;
            }
        }

        if (queen_y == king_y) {
            if (queen_x > king_x && king_x > new_queen_x) {
                cout << "Illegal move\n";
                continue;
            }
            else if (queen_x < king_x && king_x < new_queen_x) {
                cout << "Illegal move\n";
                continue;
            }
        }

        if (new_queen_x == king_x) //上、下
            if (new_queen_y + 8 == king_y || new_queen_y - 8 == king_y) {
                cout << "Move not allowed\n";
                continue;
            }

        if (new_queen_y == king_y)  //左、右
            if (new_queen_x + 1 == king_x || new_queen_x - 1 == king_x) {
                cout << "Move not allowed\n";
                continue;
            }
        if ((king == 0 && new_queen == 9) || (king == 7 && new_queen == 14) || (king == 56 && new_queen == 49) || (king == 63 && new_queen == 54)) {
            cout << "Stop\n";
            continue;
        }
        cout << "Continue\n";
    }
    return 0;
}