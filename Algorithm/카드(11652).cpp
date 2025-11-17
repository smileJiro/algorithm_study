#include<bits/stdc++.h>

using namespace std;

typedef long long _ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	unordered_map <_ll , int> numCounts;
	_ll maxNumIndex = 0;
	int maxCount = 0;

	for (int i = 0; i < n; ++i)
	{
		_ll inputNum;
		cin >> inputNum;
		++numCounts[inputNum];
		if (maxCount < numCounts[inputNum])
		{
			maxNumIndex = inputNum;
			maxCount = numCounts[inputNum];
		}
		else if (maxCount == numCounts[inputNum])
		{
			if (maxNumIndex > inputNum)
			{
				maxNumIndex = inputNum;
				maxCount = numCounts[inputNum];
			}
		}
	}

	cout << maxNumIndex << " ";


	return 0;
}