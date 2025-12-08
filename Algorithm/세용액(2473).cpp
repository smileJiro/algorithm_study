#include<bits/stdc++.h>
using namespace std;

// 용액 1개를 결정
// 이후 투포인터로 나머지 용액을 결정
// nlogn + n^2
int N;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	vector<long long> arr(N, 0);
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	int l{0}, r{N - 1};
	long long minValue = LLONG_MAX;
	int indices[3] = {0,1,2};
	for (int i = 0; i < N; ++i)
	{
		l = i + 1;
		r = N - 1;
		while (l < r)
		{
			long long sum = arr[i] + arr[l] + arr[r];
			long long absSum = abs(sum);
			if (absSum < minValue)
			{
				minValue = absSum;
				indices[0] = i;
				indices[1] = l;
				indices[2] = r;
			}

			if (sum == 0)
			{
				sort(indices, indices + 3);
				for (int idx : indices)
					cout << arr[idx] << ' ';
				cout << '\n';
				return 0;
			}
			else if (sum < 0)
				++l;
			else
				--r;

		}
	}
	
	sort(indices, indices + 3);
	for (int idx : indices)
		cout << arr[idx] << ' ';
	cout << '\n';

	return 0;
}