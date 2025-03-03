#include <iostream>

using namespace std;

int main()
{
    long long int length[55];
    length[1] = 1;
    length[2] = 2;
    for (int i = 3; i <= 50; i++)
        length[i] = length[i - 1] + length[i - 2]; //考慮尾端方塊為直立或水平

    int n;
    while (cin >> n) {
        if (!n)
            break;
        cout << length[n] << '\n';
    }
}
