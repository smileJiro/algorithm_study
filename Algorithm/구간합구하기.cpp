#include <bits/stdc++.h>

using namespace std;
int N, M;
int dp[1026][1026];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			int num;
			cin >> num;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + num;
		}
	}

	int sx{}, sy{}, ex{}, ey{}, result{};
	for (int i = 0; i < M; ++i)
	{
		cin >> sy >> sx >> ey >> ex;
		result = dp[ey][ex] - dp[sy - 1][ex] - dp[ey][sx - 1] + dp[sy - 1][sx - 1];
		cout << result <<'\n';
	}
	return 0;
}