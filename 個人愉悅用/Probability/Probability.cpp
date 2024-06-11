#include <iostream>
#include <stdlib.h> 
#include <math.h>
#include <time.h> 

using namespace std;

int main()
{
    srand(time(NULL));
    long double count = 0, count2 = 0;
    int num, all, Case = 1000000;
    for (int j = 0; j < Case; j++) {
        int one_to_six[7] = { 0 }, total = 0;
        while (1) {

            num = rand() % 6 + 1;
            one_to_six[num] = 1;
            total++;

            all = 0;
            for (int i = 1; i <= 6; i++) {
                all += one_to_six[i];
            }
            if (all == 6)
                break;
        }
        count += total;
        count2 += total * total;
    }
    cout << "E[X]= " << count / Case << '\n';
    cout << "E[X^2]= " << count2 / Case << '\n';

    return 0;
}
