#include <bits/stdc++.h>

using namespace std;

unsigned int N;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int command{};
	priority_queue<int> pq;
	vector<int> printList;
	while (N--)
	{
		cin >> command;

		if (command == 0)
		{
			if (pq.empty())
				printList.push_back(0);
			else
			{
				printList.push_back(pq.top());
				pq.pop();
			}
		}
		else
			pq.push(command);
	}

	for (auto& value : printList)
		cout << value << '\n';
	return 0;
}