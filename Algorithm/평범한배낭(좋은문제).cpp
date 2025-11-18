#include <bits/stdc++.h>

using namespace std;

int dp[102][100002]; // i번째 물건을 가방에 담았을때 최대값
int W[102];
int V[102];
int N, K;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;

	for (int i = 1; i <= N; ++i)
		cin >> W[i] >> V[i];

	for (int limit = 1; limit <= K; ++limit) // 무게 제한
	{
		for (int item = 1; item <= N; ++item) // 현재 물건
		{
			if (limit < W[item]) // 못담는 경우
				dp[item][limit] = dp[item - 1][limit];
			else
			{
				dp[item][limit] = max(V[item] + dp[item - 1][limit - W[item]], dp[item - 1][limit]);
			}
		}
	}

	cout << dp[N][K] << '\n';
	return 0;
}