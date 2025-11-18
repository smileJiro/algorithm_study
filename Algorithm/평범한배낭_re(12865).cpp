#include <bits/stdc++.h>

using namespace std;

int N, K;
int W[101]; // 물건별 무게
int V[101]; // 물건별 가치

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
	{
		cin >> W[i] >> V[i];
	}
	
	vector<vector<int>> dp(K + 1,vector<int> (N + 1, 0));
	for (int limit = 1; limit <= K; ++limit)
	{
		for (int item = 1; item <= N; ++item)
		{
			// dp[limit][item];  -> 무게 제한이 limit이고, item번 물건까지 확인했을 때, 최대 가치
			if (limit < W[item]) // 무거워서 배낭에 못넣는 경우
			{
				dp[limit][item] = dp[limit][item - 1]; // 현재 limit에서 이전 아이템까지 확인한 그대로 무게
			}
			else
			{
				dp[limit][item] = max(dp[limit - W[item]][item - 1] + V[item], dp[limit][item - 1]);
			}
		}
	}

	cout << dp[K][N] << '\n';

	return 0;
}

// 냅색 알고리즘 
// dp에 i번째 물건까지 확인했을때, 최대 가치를 기록
// 두가지 경우로 나뉘어 -> 담은 경우, 담지 않은 경우
// 담은 경우엔 해당 물건을 담았을 때의 가치와, 이전 물건까지 확인한 최대 가치를 
// 담지 않은 경우엔 이전 물건까지 확인한 최대 값을 그대로 사용
