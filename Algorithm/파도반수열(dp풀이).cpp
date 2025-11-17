#include <bits/stdc++.h>

using namespace std;

long long dp[101] = { 0,1,1,1 };
int T, N;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	for (int i = 4; i <= 100; ++i)
		dp[i] = dp[i - 2] + dp[i - 3];

	while (T--)
	{
		cin >> N;
		cout << dp[N] << '\n';
	}

	return 0;
}