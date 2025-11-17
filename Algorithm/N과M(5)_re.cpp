#include <bits/stdc++.h>

using namespace std;

int N, M;

int visited[10];
int arr[10];
int result[10];

void dfs(int level)
{
	if (level == M)
	{
		// Ãâ·Â
		for (int i = 0; i < M; ++i)
		{
			cout << result[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (visited[i] == 1)
			continue;

		result[level] = arr[i];
		visited[i] = 1;
		dfs(level + 1);
		visited[i] = 0;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	sort(arr, arr + N);

	dfs(0);
	return 0;
}