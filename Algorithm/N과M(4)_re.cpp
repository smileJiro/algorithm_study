#include <bits/stdc++.h>
using namespace std;

int N, M;

int result[10];
void dfs(int cur, int level)
{
	if (level == M)
	{
		for (int i = 0; i < M; ++i)
			cout << result[i] << ' ';

		cout << '\n';
		return;
	}

	for (int i = cur; i <= N; ++i)
	{
		result[level] = i;
		dfs(i, level + 1);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	dfs(1, 0);

	return 0;
}