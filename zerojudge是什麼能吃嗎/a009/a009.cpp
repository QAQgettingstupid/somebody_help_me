#include <iostream>

using namespace std;

int f(int n) {
    
    int ans = 0;
    (n != 0) && (ans = n + f(n - 1));

    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << f(n);
}