#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> f;
    f.push_back(0);
    f.push_back(1);
    f.push_back(2);
    int num = 2, next, N,n;
    do { //只到f[39]
        num++;
        next = f[num - 1] + f[num - 2];
        f.push_back(next);
    } while (next <100000000);

    //正式輸入
    cin >> N;
    while (N--) {
        int ans[40] = { 0 }, front = 0, now = 38;
        cin >> n;
        cout << n << " = ";
        while (now) {
            if (n >= f[now]) {
                ans[now] = 1;
                n -= f[now];
                if (front < now)
                    front = now;
                if (now > 2)
                    now -= 2;
                else
                    break;
            }
            else
                now--;
        }
        
        for (int i = front; i > 0; i--) {
            cout << ans[i];
        }
        cout << " (fib)\n";
    }
    

    return 0;
}
