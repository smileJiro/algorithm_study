#include <bits/stdc++.h>

using namespace std;

// 1. bfs로 노드 탐색 수행.
// 2. 각 노드 별로 왼쪽 자식 최대 길이 + 오른쪽 자식 최대 길이 합 구하기
// 3. max값 갱신하면서 최대 길이 찾기 -> 그게 지름
int N;
using P = pair<int, int>; // cost, index;
vector<P> graph[100001];
int visited[100001];

int maxSum = 0;
int dfs(int idx)
{
	priority_queue<int> childLens;
	for (auto& [adjCost, adjIdx] : graph[idx]) // 자식 노드 길이 모두 삽입
	{
		if (visited[adjIdx])
			continue;

		visited[adjIdx] = 1;
		int len = adjCost + dfs(adjIdx);
		childLens.push(len);
	}

	int cnt = 2, sum = 0;
	int returnValue = childLens.empty() ? 0 : childLens.top(); // 반환할 값은 미리 저장
	while (!childLens.empty() && cnt--) // 가장 긴거 두 개 뽑아서 합 구하기
	{
		sum += childLens.top(); 
		childLens.pop();
	}
	maxSum = max(maxSum, sum); // 최대 지름인지 검사
	return returnValue;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N-1; ++i)
	{
		int s, e, cost;
		cin >> s >> e >> cost;
		graph[s].emplace_back(cost, e);
		graph[e].emplace_back(cost, s); // 무방향 그래프 까지 충족
	}

	visited[1] = 1;
	dfs(1);
	cout << maxSum << '\n';
	return 0;
}