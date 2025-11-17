#include <bits/stdc++.h>

using namespace std;

// 노드 수를 입력받는다.
// 간선의 집합을 입력받는다.
// 간선을 오름 차순 정렬한다.
// 간선을 추가하기 을 확인하여 이미 같은 집합인지 검사한다.
// ParentTable의 목적 : 경로 단축 -> 이걸로 같은 집합을 검사하는 것은 아니다. -> 이걸 헷갈려했었음.
// 크루스칼 알고리즘 성능 : 간선의 수 n -> BigO(nLogn);
// 크루스칼 알고리즘의 성능 중 가장 큰 부분은 정렬이다 -> sort()함수가 nLogn이자나 평균
struct Edge
{
public:
	Edge(int u, int v, int cost)
		: u(u)
		, v(v)
		, cost(cost)
	{}
	~Edge() {}
public:
	int u;
	int v;
	int cost;
};


int findParent(vector<int>& parentTable, int idx)
{
	if (parentTable[idx] == idx)
		return idx;

	return parentTable[idx] = findParent(parentTable, parentTable[idx]);
}


int main()
{
	int n, m; // 노드 수, 간선 수
	cin >> n >> m;
	vector<int> parentTable(n);
	vector<Edge> edges(m, Edge(0,0,0));

	// 1. parentTable 초기화 자기 자신을 부모노드로 -> 경로 단축을 위한 데이터
	for (int i = 0; i < n; ++i)
		parentTable[i] = i;

	// 2. 간선 리스트 입력 받기
	for (int i = 0; i < m; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;

		edges[i] = Edge(u, v, c);
	}

	// 3. kruskal을 위한 오름차순 정렬
	sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) -> bool
		{ return a.cost < b.cost; });


	// 4. uion find 방식으로 통해 순환 검사 후 간선 추가
	int edgeCnt = 0;
	int totalCost = 0;
	int root = 0;
	vector<int> rank(n, 0); // 트리 계층이 낮은 노드가 높은 노드에게 포함되게하자.
	for (const Edge& edge : edges)
	{
		int parentU = findParent(parentTable, edge.u);
		int parentV = findParent(parentTable, edge.v);

		// 5. 트리의 깊이를 기반으로 최적화 -> findParent()의 재귀 깊이를 낮출 수 있음.
		if (parentU != parentV)
		{
			if (rank[parentU] < rank[parentV])
				parentTable[parentU] = parentV;
			else if (rank[parentV] < rank[parentU])
				parentTable[parentV] = parentU;
			else
			{
				parentTable[parentV] = parentU;
				rank[parentU] += 1;
			}
			++edgeCnt;
			totalCost += edge.cost;
		}
	}

	// 출력
	rank;
	if (edgeCnt == n - 1)
		cout << "Create MST : " << totalCost  <<  '\n';
	else
		cout << "Failed MST" << '\n';

	return 0;
}