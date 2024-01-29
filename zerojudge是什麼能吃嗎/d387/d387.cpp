#include <iostream>
#include <string>

using namespace std;
int num[1000005] = { 0 };

int main()
{
    int n, rnum, now;//0->質數 1->非質數 2->反質數 到1000000!!!!!
    for (int i = 2; i < 1000000; i++) {
        if(!num[i])
            for (int j = i*2; j < 1000000; j += i)
                num[j] = 1;
    }
    for (int i = 2; i < 1000000; i++) {
        if (!num[i]){
            rnum = 0;
            now = i;
            while (now) {
                rnum *= 10;
                rnum += now % 10;
                now /= 10;
            }
            if (i != rnum && (num[rnum] == 0 || num[rnum] == 2))
                num[i] = 2;
        }
    }
    while (cin >> n) {
        if (!num[n])
            cout << n << " is prime.\n";
        else if(num[n]==1)
            cout << n << " is not prime.\n";
        else
            cout << n << " is emirp.\n";
    }

    return 0;
}

