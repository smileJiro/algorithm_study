#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string strA = "";
	string strB = "";
	cin >> strA >> strB;

	int sizeA = strA.size();
	int sizeB = strB.size();

	vector<vector<int>> dp(sizeA + 1, vector<int>(sizeB + 1, 0));
	for (int i = 1; i <= sizeA; ++i)
	{
		for (int j = 1; j <= sizeB; ++j)
		{
			if (strA[i - 1] == strB[j - 1]) // 두 문자열이 같으면,
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	// 역추적을 해야해
	stack<char> answer;
	int answerLen = dp[sizeA][sizeB];
	int i = sizeA;
	int j = sizeB;
	while (i > 0 && j > 0)
	{
		if (dp[i - 1][j] == dp[i][j])
		{
			--i;
		}
		else if (dp[i][j - 1] == dp[i][j])
		{
			--j;
		}
		else
		{
			answer.push(strA[i - 1]);
			--i;
			--j;
		}
	}

	cout << answerLen << '\n';
	while (!answer.empty())
	{
		cout << answer.top(); 
		answer.pop();
	}
	return 0;
}