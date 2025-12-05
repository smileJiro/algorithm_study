#include <bits/stdc++.h>
using namespace std;

// 위상 정렬로 푼다. -> 방문 후 건설 최소 시간을 기록한다.
int T;
int N, K;
void TopologySort(vector<vector<int>>& graph, vector<int>& indegree, vector<int>& dp, const vector<int>& cost)
{
	queue<int> q; 
	// 1. 시작 노드 탐색(진입 차수가 0인 노드)
	for (int i = 1; i <= N; ++i)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
		}
	}

	// 2. 위상 정렬 수행
	while (!q.empty())
	{
		int idx = q.front(); q.pop();

		for (int adj : graph[idx])
		{
			// adj node의 indegree 감소, 최대 비용 갱신
			indegree[adj] -= 1;
			dp[adj] = max(dp[adj], dp[idx] + cost[adj]);
			if (indegree[adj] == 0)
			{
				q.push(adj);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;

	while (T--)
	{
		cin >> N >> K; // 노드 개수, 간선 수

		vector<vector<int>> graph(N + 1); // 인접노드
		vector<int> indegree(N + 1, 0); // 노드별 진입차수
		vector<int> cost(N + 1, 0); // 각 노드별 최소시간을 기록
		vector<int> dp(N + 1, 0);

		// 자신의 건설비용 기록
		for (int i = 1; i <= N; ++i)
		{
			cin >> cost[i];
			dp[i] = cost[i];
		}

		// 간선 입력
		int s{}, e{};
		for (int i = 0; i < K; ++i)
		{
			cin >> s >> e;
			graph[s].push_back(e);	// 간선 추가
			indegree[e] += 1;		// 진입 차수 추가
		}

		// 위상 정렬 수행 -> 방문하면서 cost 갱신
		TopologySort(graph, indegree, dp, cost);
		int target{};
		cin >> target;
		cout << dp[target] << '\n';
	}
	return 0;
}