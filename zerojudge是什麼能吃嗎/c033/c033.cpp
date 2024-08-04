#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num[1010] = { 0 };
    vector<int> prime;
    prime.push_back(1);
    for (int i = 2; i < 1010; i++) {
        if (num[i] == 0) {
            prime.push_back(i);
            for (int j = 2 * i; j < 1010; j += i)
                num[j] = 1;
        }
    }

    int N, C, K;
    vector<int> prime_now;
    while (cin >> N >> C) {
        prime_now.clear();
        K = 0;
        for (int i = 0; i < prime.size(); i++) {
            if (prime[i] > N)
                break;
            prime_now.push_back(prime[i]);
            K++;
        }

        cout << N << " " << C << ":";
        int front;

        if (K % 2) { //奇數
            if (C * 2 - 1 > K) 
                for (int i = 0; i < prime_now.size(); i++)
                    cout << " " << prime_now[i];
            else {
                front = (K - (C * 2 - 1)) / 2;
                for (int i = 0; i < C * 2 - 1; i++) {
                    if (front + i >= prime_now.size())
                        break;
                    cout << " " << prime_now[front + i];
                }
            }
        }
        else {  //偶數
            if (C * 2 > K)
                for (int i = 0; i < prime_now.size(); i++)
                    cout << " " << prime_now[i];
            else {
                front = (K - C * 2) / 2;
                for (int i = 0; i < C * 2; i++) {
                    if (front + i >= prime_now.size())
                        break;
                    cout << " " << prime_now[front + i];
                }
            }
        }
        cout << "\n\n";
    }

    return 0;
}

