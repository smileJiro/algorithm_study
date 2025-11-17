#include <bits/stdc++.h>

using namespace std;
using P = pair<int, int>; // cost, idx
int N;

void dfs(vector<vector<P>>& graph, vector<int>& dist, int idx, int& curMax, int* outFarIdx)
{
	for (auto& [adjCost, adjIdx] : graph[idx])
	{
		if (dist[adjIdx] == -1)
		{
			dist[adjIdx] = dist[idx] + adjCost;
			
			if (curMax < dist[adjIdx])
			{
				curMax = dist[adjIdx];
				*outFarIdx = adjIdx;
			}

			dfs(graph, dist, adjIdx, curMax, outFarIdx);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	vector<vector<P>> graph(N + 1);
	for (int i = 0; i < N; ++i)
	{
		int s, e, c;
		cin >> s;
		while (true)
		{
			cin >> e;
			if (e == -1)
				break;
			cin >> c;
			graph[s].emplace_back(c, e);
		}
	}

	vector<int> dist(N + 1, -1);
	int farIdx = 0;
	dist[1] = 0;
	int maxDist = 0;
	dfs(graph, dist, 1, maxDist, &farIdx);

	fill(dist.begin(), dist.end(), -1);
	dist[farIdx] = 0;
	maxDist = 0;
	dfs(graph, dist, farIdx, maxDist, &farIdx);

	cout << maxDist << '\n';
	return 0;
}



// 트리의 지름을 구하는 법은 간단하다.
// 특정 노드에서 가장 먼 노드 1개를 구한다.
// 그 노드에서 가장 먼 노드 1개를 구한다. -> 이 둘의 길이가 트리의 지름임.
// 트리의 지름을 표현하기위해 트리를 쭉 잡아 당긴 이미지를 상상해보자.
// 지름이 형성될 수 있는 두 노드를 쭉 잡아 당기면, 반드시 나머지 노드들은 그 원안에들어오게 돼 
// 이 말은 뭐냐면 -> 특정 노드 아무거나 골라서 가장 먼노드 찾으면 그게 반드시 지름을 형성하는 두 노드중 한개가 된단 의미야
// https://www.acmicpc.net/problem/1967