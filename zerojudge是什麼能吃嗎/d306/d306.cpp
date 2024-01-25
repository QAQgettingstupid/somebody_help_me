#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (!b)
        return a;
    else
        return gcd(b, a % b);

}

int main()
{
    int N,num1,num2,count=1;
    string s1, s2;
    cin >> N;
    while (N--) {
        num1 = num2 = 0;
        cin >> s1 >> s2;
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        for (int i = 0; i < s1.size(); i++)
            num1 += (s1[i]-'0') * pow(2, i);
        for (int i = 0; i < s2.size(); i++)
            num2 += (s2[i] - '0') * pow(2, i);
        cout << "Pair #" << count;
        if (gcd(num1, num2) > 1)
            cout << ": All you need is love!\n";
        else
            cout << ": Love is not all you need!\n";
        count++;
    }

    return 0;
}

