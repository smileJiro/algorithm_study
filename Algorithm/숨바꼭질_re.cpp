#include <bits/stdc++.h>

#define MAX 100000
using namespace std;
using P = pair<int, int>; // dist(time), value
int N, K;
int answer;

void bfs(int start, int target)
{
	vector<char> visited(MAX + 1);
	queue<P> q;
	q.emplace(0, start);
	visited[start] = 1;
	while (!q.empty())
	{
		auto [dist, value] = q.front(); q.pop();
		if (value == target)
		{
			cout << dist << '\n';
			return;
		}

		int newValue[3] = { value + 1, value - 1, value * 2 };
		for (int nx : newValue)
		{
			if (0 > nx || MAX < nx)
				continue;
			if (visited[nx] == 1)
				continue;

			visited[nx] = 1;
			q.emplace(dist + 1, nx);
		}

	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;

	if (K <= N)
	{
		cout << N - K << '\n';
		return 0;
	}

	bfs(N, K);
	return 0;
}