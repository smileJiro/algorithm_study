#include <bits/stdc++.h>

using namespace std;

// dp[i] = min(dp[i - i] + 현재 최소, dp[i - 2] + i-1과 i의 새로운 조합 최소);
int N;
enum COLOR { R,G,B, LAST };
int cost[1001][LAST];
int dp[1001][LAST];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	
	for (int i = 1; i <= N; ++i)
		cin >> cost[i][R] >> cost[i][G] >> cost[i][B];

	dp[1][R] = cost[1][R];
	dp[1][G] = cost[1][G];
	dp[1][B] = cost[1][B];
	
	for (int i = 2; i <= N; ++i)
	{
		dp[i][R] = min(dp[i - 1][G], dp[i - 1][B]) + cost[i][R];
		dp[i][G] = min(dp[i - 1][R], dp[i - 1][B]) + cost[i][G];
		dp[i][B] = min(dp[i - 1][R], dp[i - 1][G]) + cost[i][B];
	}

	cout << min({ dp[N][R], dp[N][G], dp[N][B] }) << '\n';
	return 0;
}