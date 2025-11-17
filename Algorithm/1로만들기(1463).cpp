#include <bits/stdc++.h>

using namespace std;
// dp로 풀자
// dp[i] = min(dp[i - 1] + 1, dp[])
int N, M;
int answer;
int dp[1000001];
int devide[] = { 3, 2 };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 2; i <= N; ++i)
	{
		dp[i] = dp[i - 1] + 1; // 1로 더하는 것을 일단 기본으로 한다.
		for (int d :devide)
		{
			if (!(i % d))
				dp[i] = min(dp[i], dp[i / d] + 1);
		}
	}

	cout << dp[N] << '\n';
	return 0;
}