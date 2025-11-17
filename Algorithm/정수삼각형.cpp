#include <bits/stdc++.h>

using namespace std;

int arr[501][501];
int sum[501];
int N;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			int num;
			cin >> arr[i][j];
		}
	}
	sum[0] = arr[0][0];
	for (int i = 1; i < N; ++i)
	{
		for (int j = i; j >= 0; --j)
		{
			if (j == 0)
				sum[j] = sum[j] + arr[i][j];
			else
				sum[j] = max(sum[j - 1], sum[j]) + arr[i][j];
		}
	}

	cout << *max_element(sum, sum + N) << '\n';
	return 0;
}