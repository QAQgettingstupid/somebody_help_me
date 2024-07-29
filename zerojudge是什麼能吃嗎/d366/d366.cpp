#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, L, U, num, now, count, temp_count, times, prime[31630] = { 0 };
    vector<int> prime_num;
    for (int i = 2; i < 31630; i++) {
        if (prime[i] == 0) {
            prime_num.push_back(i);

            for (int j = 2 * i; j < 31630; j += i) //很重要!!! j < 31630 這裡要避免每次都要重複計算像 j*i < 31630 這種
                prime[j] = 1;
        }
    }

    cin >> N;
    while (N--) {
        cin >> L >> U;
        count = 0;
        for (int i = L; i <= U; i++) {
            now = i;
            temp_count = 1;

            for (int j = 0; j < prime_num.size(); j++) {

                if (now == 1)
                    break;

                times = 0;
                while (now >= prime_num[j] && now % prime_num[j] == 0) {
                    now /= prime_num[j];
                    times++;
                }
                temp_count *= (times + 1);
            }
            if (temp_count > count) {
                count = temp_count;
                num = i;
            }
        }
        cout << "Between " << L << " and " << U << ", " << num << " has a maximum of " << count << " divisors.\n";
    }

    return 0;
}