#include <bits/stdc++.h>

using namespace std;
constexpr int INF = 1e9;
int N;
int dx[] = { -1,0,1 };
bool OOB(int x)
{
	return 0 > x || N <= x;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	vector<int> minDP(3, 0);
	vector<int> maxDP(3, 0);
	for (int i = 0; i < N; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vector<int> tmpMax(3), tmpMin(3);
		tmpMax[0] = a + max(maxDP[0], maxDP[1]);
		tmpMax[1] = b + max({ maxDP[0], maxDP[1], maxDP[2] });
		tmpMax[2] = c + max(maxDP[1], maxDP[2]);

		tmpMin[0] = a + min(minDP[0], minDP[1]);
		tmpMin[1] = b + min({ minDP[0], minDP[1], minDP[2] });
		tmpMin[2] = c + min(minDP[1], minDP[2]);

		maxDP = tmpMax;
		minDP = tmpMin;
	}

	int maxAnswer = *max_element(maxDP.begin(), maxDP.end());
	int minAnswer = *min_element(minDP.begin(), minDP.end());

	cout << maxAnswer << ' ' << minAnswer << '\n';
	return 0;
}