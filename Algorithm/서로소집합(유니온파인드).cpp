#include <bits/stdc++.h>
using namespace std;

// 서로소 집합(Disjoint Sets) : 공통 원소가 없는 두 집합 {1,2}, {3,4} -> 서로소 집합
// 아닌 경우 : {1,2}, {2,3} -> 서로소 집합이 아니다.

// 서로소 집합 자료구조 : 서로소 부분 집합들로 나누어진 원소들의 데이터를 처리하기 위한 자료구조
// 서로소 집합 자료구조는 두 종류의 연산을 지원한다.
// 합집합(Union) : 두 개의 원소가 포함된 집합을 하나의 집합으로 합치는 연산
// 찾기(Find) : 특정한 원소가 속한 집합이 어떤 집합인지 알려주는 연산
// 서로소 집합 자료구조는 합치기 찾기(Union Find) 자료구조라고 불리기도한다.

// 합집합 연산이 편향되게 이루어진다면 find 함수가 비효율적으로 동작한다
// 최악의 경우에는 find 함수가 모든 노드를 다 확인하게되어 O(v)입니다.
// 모든 노드가 같은 집합이며 1 ~ 5까지 선형적으로 연결되어있다면 >>> 1<-2<-3<-4<-5 >>> 5번노드 루트를 찾는경우 최악
// 그래서 사용하는 것이 경로 압축 기법 -> 부모 테이블의 값을 그냥 최상위 루트 노드로 설정 \
// 서로소 집합은 무방향 그래프에서 사이클을 판별할 때 사용할 수 있다.
// 배열 형태로 구현된 테이블을 만들고 해당 테이블에는 해당 노드의 최상위 루트노드를 기록
// 만약 연결하려는 두 노드의 루트 테이블이 동일하다면? -> 이는 순환하는 것으로 본다.

// 1. 유니온 파인드를 구현하자
// 2. 그래프에 간선을 추가할 때, 해당 노드의 루트노드 테이블을 갱신.
// 3. 해당 그래프에서 서로소 집합인지 확인하기 위해서 UNION_FIND(NODE, NODE) 함수를 호출
// 4. 두 노드의 루트 노드 테이블을 확인하여 같은 루트 노드를 가진다면 두 집합이 서로소가 아니다.

int findRoot(vector<int>& rootTable, int node)
{
	if (rootTable[node] == node)
		return node;

	return rootTable[node] = findRoot(rootTable, rootTable[node]);
}

void addEdge(vector<vector<int>>& graph, vector<int>& rootTable, int node1, int node2)
{
	graph[node1].push_back(node2);
	graph[node2].push_back(node1);

	int root1 = findRoot(rootTable, node1);
	int root2 = findRoot(rootTable, node2);

	if (root1 < root2)
		rootTable[root2] = root1;
	else
		rootTable[root1] = root2;
}

bool isCycle(vector<int>& rootTable, int node1, int node2)
{
	if (findRoot(rootTable, node1) == findRoot(rootTable, node2))
		return true;

	return false;
}

int main()
{
	int n;
	cin >> n; n += 1;
	vector<vector<int>> graph(n);
	vector<int> rootTable(n);
	for (int i = 0; i < n; ++i)
		rootTable[i] = i;

	while (true)
	{
		int n, m;
		cin >> n >> m;

		if (isCycle(rootTable, n, m))
		{
			cout << "해당 노드간 간선 추가 시 사이클 발생" << '\n';
		}
		else
		{
			addEdge(graph, rootTable, n, m);
		}
	}
	return 0;
}