#include <bits/stdc++.h>

using namespace std;

int32_t rootTable[1001];
int32_t rankTable[1001];

int32_t findRoot(int idx)
{
	if (idx == rootTable[idx])
		return idx;

	return rootTable[idx] = findRoot(rootTable[idx]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int32_t n, m;
	cin >> n >> m;
	
	// 1. rootTable 정렬
	for (int32_t i = 1; i <= n; ++i)
		rootTable[i] = i;

	// 2. 간선 추가 및 루트 테이블 갱신 완료.
	int32_t count = n;
	for (int32_t i = 0; i < m; ++i)
	{
		int32_t u, v;
		cin >> u >> v;
		// 간선을 추가할 때, 두 노드의 rootTable 업데이트
		int32_t rootU = findRoot(u);
		int32_t rootV = findRoot(v);

		if (rootU == rootV)
			continue;

		// 두 노드의 root 비교
		if (rankTable[rootU] < rankTable[rootV]) // 랭크 낮은 애가 높은 애한테 삽입
			rootTable[rootU] = rootV;
		else if (rankTable[rootU] > rankTable[rootV])
			rootTable[rootV] = rootU;
		else
		{
			rootTable[rootV] = rootU;
			++rankTable[rootU];
		}
		--count;
	}

	cout << count << '\n';
	return 0;
}