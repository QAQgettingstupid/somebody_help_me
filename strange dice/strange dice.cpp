#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));
    double t = 1000;
    int number[7] = { 0 };
    for (int i = 0; i < 1000; i++) {
        int num = rand() % 10 + 1;
        if (num <= 5) {
            number[num]++;
            cout << "點數: " << num << '\n';
        }
        else
        {
            number[6]++;
            cout << "點數: " << 6 << '\n';
        }
    }
    for (int i = 1; i <= 6; i++)
        cout << "骰出" << i << "點的機率為: " << number[i] / t << '\n';
}
