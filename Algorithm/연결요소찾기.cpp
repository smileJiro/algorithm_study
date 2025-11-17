#include<Bits/stdc++.h>

using namespace std;


int main()
{
	int N, M;

	cin >> N >> M;

	vector<vector<int>> adjList(N, vector<int>(M));
	vector<bool> checkList(N * M);
	for (int i = 0; i < M; ++i)
	{
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	int componentCount = 0;
	for (int i = 0; i < N; ++i)
	{
		if(checkList[i])
	}


	return 0;
}