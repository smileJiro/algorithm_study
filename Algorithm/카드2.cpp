#include<bits/stdc++.h>

using namespace std;


int main()
{
	int n;
	cin >> n;

	queue<int> queue;

	for (int i = 1; i <= n; ++i)
	{
		queue.push(i);
	}

	bool isPop = true;
	while (1 < queue.size())
	{
		if (isPop)
		{
			queue.pop();
			isPop = false;
		}
		else
		{
			int value = queue.front();
			queue.pop();
			queue.push(value);
			isPop = true;
		}
	}
	cout << queue.front() << "\n";
	return 0;
}