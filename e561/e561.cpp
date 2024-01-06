#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, L;
    cin >> n;
    while (n--) {
        cin >> L;
        int count = 0;
        vector<int> v(L);
        for (int i = 0; i < L; i++)
            cin >> v[i];
        for (int i = 0; i < L-1; i++) {
            for (int j = 0; j < L-1; j++) {
                if (v[j] > v[j + 1]) {
                    swap(v[j], v[j + 1]);
                    count++;
                }
            }
        }
        cout << "Optimal train swapping takes " << count << " swaps.\n";
    }
}