#include <bits/stdc++.h>

using namespace std;
constexpr int INF = 1e9;
using Edge = tuple<int, int, int>; // s,e,c
int TC, N, M, W;
bool Bellmanford(vector<Edge>& edges)
{
	vector<int> dist(N + 1, 0); 
	// 모든 노드로 향할 수 있는 스페셜 노드가 있다고 가정.
	// 즉 모든 dist 값을 0으로 초기화하고, -1 음수 간선이 있을때 업데이트 될거야,
	// 해당 반례 해결 때문에
	//1
	//3 1 1
	//1 2 2
	//3 3 1 
	int count = N;
	

	while (count--)
	{
		bool isUpdate = false;
		for (auto& [s, e, c] : edges)
		{
			if (dist[e] > dist[s] + c)
			{
				isUpdate = true;
				dist[e] = dist[s] + c;

				if (count == 0)
					return false;
			}
		}
		if (!isUpdate)
			break;
	}

	return true;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> TC;

	while (TC--)
	{
		cin >> N >> M >> W;
		vector<Edge> EdgeList;
		for (int i = 0; i < M; ++i)
		{
			int s, e, c;
			cin >> s >> e >> c;
			EdgeList.emplace_back(s,e,c);
			EdgeList.emplace_back(e,s,c);
		}
		for (int i = 0; i < W; ++i)
		{
			int s, e, c;
			cin >> s >> e >> c;
			EdgeList.emplace_back(s, e, -c);
		}

		if (!Bellmanford(EdgeList)) // 벨만 포드 돌려서 N 번째에도 갱신되냐 묻는거
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}