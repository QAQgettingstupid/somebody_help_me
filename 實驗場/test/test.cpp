#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct compare
{
	bool operator()(int a, int b)
	{
		return a > b; // For min-heap
	}
};

bool mycomparer(int a, int b)
{
	return a > b; 
}

int main()
{
	priority_queue<int,vector<int>,compare> pq;
	vector<int> v = { 10, 5, 20, 15, 30 };

	pq.push(10);
	pq.push(5);
	pq.push(20);
	pq.push(15);
	pq.push(30);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << '\n';

	sort(v.begin(), v.end(), mycomparer);
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << '\n';

}
