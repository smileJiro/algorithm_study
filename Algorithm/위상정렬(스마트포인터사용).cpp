#include <bits/stdc++.h>

using namespace std;

struct Node
{
public:
	Node()
		: idx(idxID++)
		, inDegree(0)
	{}
	~Node() {}
public:
	static int idxID;

public:
	int idx;
	int inDegree;

public:
	vector<shared_ptr<Node>> adj;
	
	//int outDegree; // 인접 노드의 개수
};
int Node::idxID = 0;

bool topologySort(const vector<shared_ptr<Node>>& graph, vector<int>& result)
{
	int size = graph.size(); // 0번노드 빈노드
	int cnt = 0;

	queue<shared_ptr<Node>> q;

	for (int i = 1; i < size; ++i)
	{
		auto& node = graph[i];
		if(node->inDegree == 0)
		{
			q.push(node);
			result.push_back(i);
		}
	}
	
	while (!q.empty())
	{
		auto& cur = q.front(); q.pop(); ++cnt;

		for (auto& adjNode : cur->adj)
		{
			adjNode->inDegree -= 1;
			if (adjNode->inDegree == 0)
			{
				q.push(adjNode);
				result.push_back(adjNode->idx);
			}
		}
		
	}
	
	return size - 1 == cnt;
}

int main()
{
	int n, e;
	cin >> n >> e; // 노드 수, 간선 수

	vector<shared_ptr<Node>> graph(n + 1);
	for (int i = 0; i < n + 1; ++i)
		graph[i] = make_shared<Node>();

	for (int i = 0; i < e; ++i)
	{
		int u, v;
		cin >> u >> v;
		graph[u]->adj.push_back(graph[v]);
		graph[v]->inDegree += 1;
	}

	vector<int> result;

	bool isSort = topologySort(graph, result);

	if (isSort)
		for (int i = 0; i < result.size(); ++i)
			cout << result[i] << ' ';
	else
		cout << "Failed : is Not DAG" << '\n';

	return 0;
}

// 위상 정렬이란 : 사이클이 없는, 방향 그래프의 모든 노드를 방향성에 거스르지 않도록 순서대로 나열하는 것을 의미한다.
// 예시) 선수 과목을 고려한 학습 순서 설정 

// 진입 차수(Indegree) : 특정한 노드로 들어오는 간선의 개수
// 진출차수(Outdegree) : 특정한 노드에서 나가는 간선의 개수

// 위상 정렬 알고리즘
// 큐를 이용해서 구현하거나, dfs를 통해서 구현이 가능하다.
// 1. 진입 차수가 0인 모든 노드를 큐에 넣는다.
// 2. 큐가 빌 때 까지 다음의 과정을 반복한다.
// - 큐에서 원소를 꺼내 해당 노드에서 나가는 간선을 그래프에서 제거합니다.
// - 새롭게 진입차수가 0이된 노드를 큐에 넣습니다.
// 결과적으로 각 노드가 큐에 들어온 순서가 위상 정렬을 수행한 결과와 같습니다.
// 그래프는 사이클이 없는 방향 그래프(DAG)여야 합니다.
// 사이클이 있다면, 그 사이클에 포함된 모든 노드는 진입차수가 1이상이 된다.

// 위상 정렬의 특징
// 위상 정렬은 DAG에 대해서만 수행할 수 있습니다.
// - DAG(Direct Acyclic Graph) : 순환하지 않는 방향 그래프
// 위상 정렬에서는 여러 가지 답이 존재할 수 있습니다.
// - 한 단계에서 큐에 새롭게 들어가는 원소가 2개 이상이라면, 삽입 우선순위 조건에 따라 여러 가지 답이 존재합니다.
// 모든 원소를 방문하기 전 큐가 빈다면? -> 이는 사이클이 존재하는 그래프라는 것을 판단할 수 있습니다.
// 사이클에 포함된 원소 중 어떠한 원소도 큐에 들어갈 수 없습니다.
// 스택을 활용한 DFS를 이용해 위상 정렬을 수행할 수도 있습니다.