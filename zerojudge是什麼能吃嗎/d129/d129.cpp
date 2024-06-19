#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int count = 1, ugly[1550], index = 0, index2 = 0, index3 = 0, index5 = 0;
    ugly[0] = 1;
    while (count < 1500) {
        index++;
        ugly[index] = min({ ugly[index2] * 2, ugly[index3] * 3, ugly[index5] * 5 });

        if (ugly[index2] * 2 == ugly[index])
            index2++;
        if (ugly[index3] * 3 == ugly[index])
            index3++;
        if (ugly[index5] * 5 == ugly[index])
            index5++;
        count++;
    }
    cout << "The 1500'th ugly number is " << ugly[index] << ".";
}

