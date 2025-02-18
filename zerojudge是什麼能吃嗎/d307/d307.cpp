#include <iostream>

using namespace std;

int main()
{
    int prime[32768] = {0}; // 1 -> not prime, 0 -> prime
    prime[0] = prime[1] = 1;
    for (int i = 2; i < 32768; i++) {
        if (!prime[i])
            for (int j = i*2; j < 32768; j += i)
                prime[j] = 1;
    }
    
    int n, ans;
    
    while (cin >> n) {
        if (!n)
            break;

        ans = 0;
        for (int i = 2; i <= n / 2; i++)
            if (!prime[i] && !prime[n - i])
                ans++;

        cout << ans << '\n';
    }
}
