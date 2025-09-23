#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n, layer, f_total;
	int round = 1;

	while (cin >> n) {

		if (round > 1)
			cout << '\n';

		layer = (int)ceil((-1 + sqrt(1 + 8 * n)) / 2);
		f_total = (1 + layer - 1) * (layer - 1) / 2;

		//偶數行, 偶下
		if (layer % 2 == 0) {
			cout << "TERM " << n << " IS " << n - f_total << "/" << (layer + 1) - (n - f_total);
		}
		//奇數行, 奇上
		else
			cout << "TERM " << n << " IS " << (layer + 1) - (n - f_total) << "/" << n - f_total;
		round++;
	}
}
