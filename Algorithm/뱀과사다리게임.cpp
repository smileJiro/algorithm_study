#include <bits/stdc++.h>

using namespace std;
using P = pair<int, int>;
int N, M;
int numTable[101];
bool visited[101];
int main()
{
	for (int i = 0; i < 101; ++i)
		numTable[i] = i;

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	int s{}, e{};
	for (int i = 0; i < N; ++i)
	{
		cin >> s >> e;
		numTable[s] = e;
	}
	for (int i = 0; i < M; ++i)
	{
		cin >> s >> e;
		numTable[s] = e;
	}

	// BFS
	
	queue<P> q;
	q.emplace(1, 0);
	while (!q.empty())
	{
		auto [idx, level] = q.front(); q.pop();
		if (idx == 100)
		{
			cout << level << '\n';
			break;
		}
		for (int i = 6; i > 0; --i)
		{
			int nIdx = idx + i;
			if (nIdx > 100)
				continue;
			else if (visited[numTable[nIdx]])
				continue;
			else
			{
				visited[numTable[nIdx]] = 1; // 방문체크
				q.emplace(numTable[nIdx], level + 1);
			}
		}
	}
	return 0;
}
