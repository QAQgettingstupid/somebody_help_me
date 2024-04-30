#include <iostream>
#include <algorithm>

using namespace std;

class num {
    private:
        int number, mod;
    public:
        void set_number() {
            int n;
            cin >> n;
            number = n;
        }
        void set_mod(int m) {
            mod = number % m;
        }
        int get_number() {
            return number;
        }
        int get_mod() {
            return mod;
        }
};

bool compare(num a, num b) { //a後 b前
    if (a.get_mod() == b.get_mod()) {
        if (a.get_number() % 2 + b.get_number() % 2 == 1)//1奇1偶
            return a.get_number() % 2 > b.get_number() % 2;
        else if (a.get_number() % 2 && b.get_number() % 2) //2奇
            return a.get_number() > b.get_number();
        else //2偶
            return a.get_number() < b.get_number();
    }
    return a.get_mod() < b.get_mod();
}


int main()
{
    int n, m;
    while (cin >> n >> m) {
        if (n == m && m == 0)
            break;
        num Num[10010];
        for (int i = 0; i < n; i++) {
            Num[i].set_number();
            Num[i].set_mod(m);
        }
        sort(Num, Num + n, compare);
        //輸出
        cout << n << " " << m << '\n';
        for (int i = 0; i < n; i++)
            cout << Num[i].get_number() << '\n';
    }
    cout << 0 << " " << 0 << '\n';
    return 0;
}
