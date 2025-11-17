#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string A = "";
	string B = "";
	cin >> A >> B;

	int sizeA = A.size();
	int sizeB = B.size();
	vector<vector<int>> dp(sizeA + 1, vector<int>(sizeB + 1, 0)); // 배열 전부 0 초기화

	for (int i = 1; i <= sizeA; ++i)
	{
		for (int j = 1; j <= sizeB; ++j)
		{
			if (A[i - 1] == B[j - 1]) // 현재 비교하는 두 문자가 같다면, A,B의 이전 문자 기준 최장 공통 부분수열 길이 + 1 수행
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else // 만약 다르다면, 지금까지의 최대 증가 수열의 길이를 유지
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	// 문자열 역추적하기.
	int ny = sizeA;
	int nx = sizeB;
	string answer = "";
	while (ny > 0 && nx > 0)
	{
		if (A[ny - 1] == B[nx - 1]) // 현재 두 문자가 같다면, 바로 대각이동
		{
			answer += A[ny - 1];
			--ny; --nx;
		}
		else if (dp[ny - 1][nx] == dp[ny][nx])
			--ny;
		else if (dp[ny][nx - 1] == dp[ny][nx])
			--nx;
	}
	reverse(answer.begin(), answer.end());
	cout << answer << '\n';
	return 0;
}