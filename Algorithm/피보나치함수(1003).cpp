#include <bits/stdc++.h>

using namespace std;

pair<int, int> dp[42];
int T, N;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;

	dp[0] = { 1, 0 };
	dp[1] = { 0, 1 };
	for (int i = 2; i <= 40; ++i)
	{
		int zero = dp[i - 1].first + dp[i - 2].first;
		int one = dp[i - 1].second + dp[i - 2].second;
		dp[i] = { zero , one };
	}
	while (T--)
	{
		cin >> N;
		cout << dp[N].first << ' ' << dp[N].second << '\n';
		
	}
	return 0;
}