#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int ans[14];
    
    for (int k = 1; k <= 13; k++) {
        
        int total = 2 * k;
        int m = k + 1;
        int round, killed, next;

        for (m;;m++) {
            round = 1;
            if ((m - 1) % total >= k) {
                killed = 1;
                next = (m - 1) % total;
                round++;

                while(killed < k) {
                    next = (next + (m - 1)) % (total - round + 1);

                    if(next<k)
						break;
                    else {
                        round++;
                        killed++;
                    }
				}

                if (killed == k) {
                    ans[k] = m;
                    break;
                }
            }
        }
    }
    int k;

    while (cin >> k) {

		if (k == 0) 
            break;

        cout << ans[k] << '\n';
    }
}
