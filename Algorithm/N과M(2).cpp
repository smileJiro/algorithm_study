#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];
bool visited[10];
void dfs(int value, int level)
{
	if (level == m)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = value; i <= n; ++i)
	{
		arr[level] = i;
		dfs(i + 1, level + 1);
	}
}
int main()
{
	cin >> n >> m;

	dfs(1, 0);
	return 0;
}