#include <bits/stdc++.h>
using namespace std;
using T = tuple<int, int, int>; // s, e, c
constexpr int INF = 1e9;


int N, M;
bool Bellmanford(vector<T>& edges, vector<long long>& dist, int s)
{
	dist[s] = 0;
	int count = N;
	while (count--) // N - 1번 수행한다는게 중요해. i사용한 for문은 i에 뭔가 의미부여하게되서 헷갈려
	{
		bool isUpdate = false;
		for (auto& [s, e, c] : edges)
		{
			if (dist[s] == INF)
				continue;

			if (dist[e] > dist[s] + c)
			{
				dist[e] = dist[s] + c;
				isUpdate = true;
				if (count == 0) // N 번 수행한거야. 이때 만약, 갱신이 일어났다? 이건 음수 순환임
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
	cin >> N >> M;
	
	vector<T> edges;
	vector<long long> dist(N + 1, INF);
	// 1. 간선 리스트 만든다.
	for (int i = 0; i < M; ++i)
	{
		int s, e, c;
		cin >> s >> e >> c;
		edges.emplace_back(s,e,c);
	}
	
	if (Bellmanford(edges, dist, 1))
	{
		for (int i = 2; i <= N; ++i)
		{
			if (dist[i] == INF)
				cout << -1;
			else
				cout << dist[i];

			cout << '\n';
		}
	}
	else
		cout << -1 << '\n';

	return 0;
}