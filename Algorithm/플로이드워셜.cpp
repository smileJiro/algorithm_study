#include <bits/stdc++.h>

using namespace std;

// 다익스트라보다 구현이 쉽다.
// 2차원 테이블을 사용한다.
// 노드의 개수가 적을 때 사용한다.
// 모든 노드가 다른 노드에 대한 최단 경로를 갱신하는 알고리즘이다.
// 각 단계마다 특정한 노드 k를 거쳐가는 경우를 확인한다
// a에서 b로 가는 최단거리보다 a에서 k를 거쳐 b로 가는 거리가 더 짧은지 검사한다.
// 플로이드 워셜에서는 기본적으로 최대 노드개수가 약 500개 이하임 
// n의 3제곱의 시간복잡도 이기때문에 -> 노드 개수가 많으면 시간 복잡도 오바임.

int main()
{
	int n = 4;
	constexpr int INF = 1e9;
	vector<vector<int>> graph(n,vector<int>(n, INF));
	for (int i = 0; i < n; ++i)
		graph[i][i] = 0;

	graph[0][1] = 4;
	graph[0][3] = 6;

	graph[1][0] = 3; 
	graph[1][2] = 7; 

	graph[2][0] = 5; 
	graph[2][3] = 4; 

	graph[3][2] = 2; 

	// 1. 현재 노드를 거쳐가는 경로가 더 짧은지 판단
	for (int k = 0; k < n; ++k)
	{
		for (int start = 0; start < n; ++start)
		{
			for (int end = 0; end < n; ++end)
			{
				graph[start][end] = min(graph[start][end], graph[start][k] + graph[k][end]);
			}
		}
	}

	return 0;
}