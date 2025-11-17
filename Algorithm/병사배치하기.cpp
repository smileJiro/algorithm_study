#include <bits/stdc++.h>
using namespace std;

int main()
{
	while (true)
	{
		int n;
		cin >> n;

		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
			cin >> arr[i];

		vector<int> dp(n, 1);
		int maxValue = 0;
		// 가장 긴 감소하는 부분 수열 : i 보다 '큰' j의 dp 테이블 정보중 가장 큰 값 + 1이 i의 dp
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (arr[j] > arr[i])
				{
					// 자신보다 큰 j에 대하여, dp를 참조하고 해당 dp + 1을 수행
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			maxValue = max(maxValue, dp[i]);
		}

		cout << maxValue << '\n';
	}
	
	return 0;
}