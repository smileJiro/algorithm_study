#include <bits/stdc++.h>

using namespace std;
// 인풋으로 그래프 만들고 >> 그래프 탐색 돌리면서 부모 인덱스 저장하자.
vector<int> graph[100001]; // 인접 리스트, 무방향성 그래프로 보자 인풋 순서가 루트부터 간다는 말은 없어
int visited[100001];
int parent[100001];
int N;

void dfs(int node, int parentNode)
{
	if (visited[node])
		return;

	visited[node] = 1;
	parent[node] = parentNode;

	for(int adj : graph[node])
	{
		dfs(adj, node);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i < N; ++i)
	{
		int a, b;
		cin >> a >> b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}

	dfs(1, 0); // 부모 노드 계산


	for (int i = 2; i <= N; ++i)
	{
		cout << parent[i] << '\n';
	}
	return 0;
}