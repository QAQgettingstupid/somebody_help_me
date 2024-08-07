#include <iostream>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <vector>

using namespace std;


void print(int ans, vector<int> prime) {
    int Power;
    string s_Power, s_prime, to_print = "";
    for (int i = 0; i < prime.size(); i++) {
        Power = 0;
        if (ans == 1)
            break;
        else if (ans % prime[i] == 0) {
            while (ans % prime[i] == 0) {
                Power++;
                ans /= prime[i];
            }
            s_prime = to_string(prime[i]);
            s_Power = to_string(Power);
            reverse(s_prime.begin(), s_prime.end());
            reverse(s_Power.begin(), s_Power.end());
            to_print += " " + s_Power + " " + s_prime;
        }
    }
    reverse(to_print.begin(), to_print.end());
    cout << to_print << '\n';
}



int main()
{
    int prime_num[32770] = { 0 };
    vector<int> prime;
    for (int i = 2; i <= 32767; i++) {
        if (prime_num[i] == 0) {
            prime.push_back(i);
            for (int j = 2 * i; j <= 32767; j += i)
                prime_num[j] = 1;
        }
    }
    
    string X, s_num, s_Power;
    stringstream s;
    int ans, num, Power;
    while (getline(cin,X)) {
        if (X == "0")
            break;
        ans = 1;
        s << X;
        while (s >> s_num >> s_Power) {
            num = stoi(s_num);
            Power = stoi(s_Power);
            ans *= pow(num, Power);
        }
        ans--;
        print(ans, prime);
        s.clear();
    }

    return 0;
}
