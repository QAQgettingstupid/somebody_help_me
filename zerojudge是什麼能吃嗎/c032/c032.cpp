#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    int n;

    cout << "PERFECTION OUTPUT\n";
    
    while (cin >> n) {
        if (n == 0)
            break;

		int total = 0;
        vector<int> ans;
		ans.push_back(1);

        for (int i = 2; i < sqrt(n); i++) {
            if(n % i == 0) {
                ans.push_back(i);
                ans.push_back(n/i);
			}
        }
        
        for(auto it:ans)
			total += it;
        
        cout << setw(5) << setfill(' ') << n << "  ";
        
        if (total < n || n == 1)
            cout << "DEFICIENT\n";
        else if (total == n)
            cout << "PERFECT\n";
        else
            cout << "ABUNDANT\n";
    }
    cout << "\n";
    cout << "END OF OUTPUT";
}