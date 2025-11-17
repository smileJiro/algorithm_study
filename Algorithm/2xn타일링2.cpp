#include <bits/stdc++.h>

using namespace std;


int N;
constexpr int MOD = 10007;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	vector<int> dp(1001, 0);
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= N; ++i)
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % MOD;
		 
	cout << dp[N] << '\n';
	return 0;
}