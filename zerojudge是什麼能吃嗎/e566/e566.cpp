#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    bool flag;
    vector<int> num;
    while (cin >> n >> m) {
        if (m <= 1) {
            cout << "Boring!\n";
            continue;
        }
        flag = true;
        num.push_back(n);
        while (n != 1) {
            if (n % m) {
                cout << "Boring!\n";
                flag = false;
                break;
            }
            else {
                num.push_back(n / m);
                n /= m;
            }
        }
        if (flag) {
            cout << num[0];
            for (int i = 1; i < num.size(); i++)
                cout << " " << num[i];
            cout << '\n';
        }
        num.clear();   
    }

    return 0;
}

