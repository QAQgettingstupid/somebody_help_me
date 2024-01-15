#include <iostream>
#include <vector>
#include <string>

using namespace std;

void move(int face,int &x, int &y) {

    switch (face) {
    case 0:
        y=y + 1;
        break;
    case 1:
        x = x + 1;
        break;
    case 2:
        y = y - 1;
        break;
    case 3:
        x = x - 1;
    }
}

string word(int face) {
    switch (face) {
    case 0:
        return " N";
        break;
    case 1:
        return " E";
        break;
    case 2:
        return " S";
        break;
    case 3:
        return " W";
    }
}

int main()
{
    int rx, ry, x, y, face,px,py;
    string step;
    cin >> rx >> ry;
    vector<vector<vector<int>>> space(rx+1, vector<vector<int>>(ry+1, vector<int>(4, 0)));
    while (cin >> x) {
        cin >> y >> step;
        bool lost = 0;
        px = x;
        py = y;
        if (step == "N")//N->0 E->1 S->2 W->3
            face = 0;
        else if (step == "E")
            face = 1;
        else if (step == "S")
            face = 2;
        else
            face = 3;
        getline(cin, step);
        getline(cin, step);
        for (int i = 0; i < step.size(); i++) {
            switch (step[i]) {
                case 'R':
                    face = (face + 1) % 4;
                    break;
                case 'L':
                    face = (face + 3) % 4;
                    break;
                case 'F':
                    if (!space[x][y][face])
                        move(face, x, y);
            }
            if (x > rx || y > ry || x < 0 || y < 0) {
                cout << px << " " << py <<word(face)<< " LOST\n";
                if (px == rx && py == ry) {
                    space[px][py][0] = 1;
                    space[px][py][1] = 1;
                }
                else if (px == 0 && py == 0) {
                    space[px][py][2] = 1;
                    space[px][py][3] = 1;
                }
                else if (px == 0) {
                    space[px][py][0] = 1;
                    space[px][py][3] = 1;
                }
                else if (py == 0) {
                    space[px][py][1] = 1;
                    space[px][py][2] = 1;
                }
                else
                    space[px][py][face] = 1;
                lost = 1;
                break;
            }
            else {
                px = x;
                py = y;
            }
        }
        if(lost==0)
            cout << x << " " << y << word(face) << "\n";
    }
    return 0;
}
