#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int visited[10];
int result[10];
void dfs(int level)
{
	if (level == m)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << result[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (false == visited[i])
		{
			result[level] = arr[i];
			visited[i] = true;
			dfs(level + 1);
			visited[i] = false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	dfs(0);

	return 0;
}