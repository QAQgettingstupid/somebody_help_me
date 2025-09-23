#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int N;
	string S,str1,str2;
	int end;
	vector<string> ans;

	while (cin >> N) {

		N /= 2;
		end = 1;

		for (int i = 0; i < N; i++)
			end *= 10;

		for (int i = 0; i < end; i++) {
			for (int j = 0; j < end; j++) {
				if ((i + j) * (i + j) == i * end + j) {
					
					str1 = to_string(i);
					str2 = to_string(j);
					
					while (str1.size() < N)
						str1 = "0" + str1;

					while (str2.size() < N)
						str2 = "0" + str2;
					
					S = str1 + str2;
					
					ans.push_back(S);
				}
			}
		}

		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << '\n';
		ans.clear();
	}
}
