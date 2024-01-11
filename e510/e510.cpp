#include <iostream>
#include <iomanip>
#include <math.h>


using namespace std;

int main()
{
    // a/(1-r)無窮等比級數和公式, a->首項,r->公比(-1<r<1)
    int S, N, i;
    double p, ans;
    cin >> S;
    while (S--) {
        cin >> N >> p >> i;
        ans = (pow((1 - p), (i - 1)) * p) / (1 - pow((1 - p), N));
        cout << fixed << setprecision(4) << ans << '\n';
    }
    return 0;
}
