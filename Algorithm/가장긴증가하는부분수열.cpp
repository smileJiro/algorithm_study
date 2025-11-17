#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1001];
int dp[1001];
int LIS_DP()
{
	int result = 0;
	for (int i = 0; i < n; ++i)
	{
		dp[i] = 1; // 모든 dp테이블은 1로 초기화 후 시작.
		for (int j = 0; j < i; ++j)
		{
			if (arr[j] < arr[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		result = max(result, dp[i]);
	}

	return result;
}
int LIS()
{
	vector<int> lis;
	lis.push_back(arr[0]);
	int idx = 1;
	while (idx < n)
	{
		if (arr[idx] > lis.back())
			lis.push_back(arr[idx]);
		else
		{
			auto iter = lower_bound(lis.begin(), lis.end(), arr[idx]);
			*iter = arr[idx];
		}
		++idx;
	}

	return lis.size();
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	//cout << LIS();
	cout << LIS_DP();

	return 0;
}