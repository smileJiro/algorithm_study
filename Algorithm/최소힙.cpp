#include <bits/stdc++.h>
#include <queue>
using namespace std;

int N;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; ++i)
	{
		int command;
		cin >> command;
		if (command)
			pq.emplace(command);
		else
		{
			if (pq.empty())
			{
				cout << 0 << '\n';
				continue;
			}
			cout << pq.top() << '\n';
			pq.pop();
		}
	}

	return 0;
}