#include <bits/stdc++.h>

using namespace std;

int N, E;
vector<int> graph[101]; // 노드 별 인접 리스트
int visited[101];

void bfs(int idx, int* answer)
{
	if (visited[idx])
		return;

	queue<int> q; // 인덱스
	q.emplace(idx);
	visited[idx] = 1;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int adj : graph[cur])
		{
			if (!visited[adj])
			{
				q.emplace(adj);
				visited[adj] = 1;
				*answer += 1;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> E;

	for (int i = 0; i < E; ++i)
	{
		int s, e;
		cin >> s >> e;
		graph[s].emplace_back(e);
		graph[e].emplace_back(s); // 양방향
	}

	// 1번만 체크
	int answer = 0;
	bfs(1, &answer);

	cout << answer << '\n';
	return 0;
}