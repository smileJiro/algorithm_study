#include <bits/stdc++.h>

using namespace std;

bool visited[8] = {};
vector<int> graph[8];

void bfs(vector<int> graph[], int start)
{
	queue<int> queue;
	queue.push(start);
	visited[start] = true;
	while (!queue.empty())
	{
		int current = queue.front();
		queue.pop();
		
		cout << current << ' ';
		for (int i : graph[current])
			if(false == visited[i])
			{
				queue.push(i);
				visited[i] = true;
			}
		
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

	bfs(graph, 0);

	return 0;
}