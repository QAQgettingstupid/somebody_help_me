#include <iostream>

using namespace std;

int main()
{
    int over = 1, n;
    double sum = 0, number, average,previous;
    cout << "please enter n: (limitation: 0 < n < 2147483647)\n";
    cin >> n;

    if (n <= 0) { //over�P�_�O�_�����`���A�o�� 0->���`�o�� ,1->���`�B��
        over = 0;
        cout << "error n can't be 0 or lesser\n";
    }
    for (int i = n; i > 0; i--) {
        cin >> number;
        previous = sum;
        sum += number;
        if (sum - previous != number) {
            over = 0;
            cout << "error overflow occurred\n";
            break;
        }
    }
    if (over) {
        average = sum / n;
        cout << "sum=" << sum<<'\n';
        cout << "average=" << average;
    }
    return 0;
}
