#include <bits/stdc++.h>

using namespace std;
int T, N;
int board[2][100002];
int dp[2][100002];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;

	while (T--)
	{
		cin >> N;

		for (int i = 0; i < 2; ++i)
		{
			for (int j = 1; j <= N; ++j)
				cin >> board[i][j];
		}

		dp[0][1] = board[0][1];
		dp[1][1] = board[1][1];
		for (int j = 2; j <= N; ++j)
		{
			dp[0][j] = max(dp[1][j - 1], dp[1][j - 2]) + board[0][j];
			dp[1][j] = max(dp[0][j - 1], dp[0][j - 2]) + board[1][j];
		}
		cout << max(dp[0][N], dp[1][N]) << '\n';
	}

	return 0;
}