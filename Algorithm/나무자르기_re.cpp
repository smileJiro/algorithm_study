#include <bits/stdc++.h>

using namespace std;

int N, M;
bool isPossible(vector<int>& treeList, int sawHeight, int targetLen)
{
	long long sum = 0;
	for (int tree : treeList)
		sum += max(0, tree - sawHeight);

	return sum >= targetLen;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	vector<int> treeList(N, 0);
	for (int i = 0; i < N; ++i)
		cin >> treeList[i];

	int s{}, e{ *max_element(treeList.begin(), treeList.end()) }, m{};
	int answer = 0;
	while (s <= e)
	{
		m = (s + e) / 2;
		if (isPossible(treeList, m, M))
		{
			answer = m;
			s = m + 1;
		}
		else
			e = m - 1;
	}

	cout << answer << '\n';
	return 0;
}