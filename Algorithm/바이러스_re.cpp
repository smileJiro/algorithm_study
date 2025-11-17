#include <bits/stdc++.h>

using namespace std;
// 유니온파인드로 풀어보자

int N, M;
int rootTable[102];

int findRoot(int n)
{
	if (rootTable[n] == n)
		return n;

	return rootTable[n] = findRoot(rootTable[n]);
}

void addEdge(int n1, int n2)
{
	int root1 = findRoot(n1);
	int root2 = findRoot(n2);

	if (root1 < root2)
		rootTable[root2] = root1;
	else
		rootTable[root1] = root2;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i <= N; ++i)
		rootTable[i] = i;

	int n1, n2;
	for (int i = 0; i < M; ++i)
	{
		cin >> n1 >> n2;
		addEdge(n1, n2);
	}

	int target = 1;
	int targetRoot = findRoot(target);
	int answer = 0;
	for (int i = 0; i <= N; ++i)
	{
		if (findRoot(i) == targetRoot)
			answer += 1;
	}

	cout << answer - 1 << '\n';
	return 0;
}