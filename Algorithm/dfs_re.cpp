#include <bits/stdc++.h>

using namespace std;

bool visited[8] = {};
vector<int> graph[8];

void dfs(int idx)
{
	visited[idx] = true;
	cout << idx + 1 << ' ';
	for (int i : graph[idx])
	{
		if (false == visited[i])
			dfs(i);
	}
}
int main()
{
	graph[0] = { 1,2,7 };
	graph[1] = { 0,6 };
	graph[2] = { 0,3,4 };
	graph[3] = { 2,4 };
	graph[4] = { 2,3 };
	graph[5] = { 6 };
	graph[6] = { 1,5,7 };
	graph[7] = { 0,6 };

	for (int i = 0; i < 8; ++i)
		sort(graph[i].begin(), graph[i].end());

	dfs(6);
	return 0;
}