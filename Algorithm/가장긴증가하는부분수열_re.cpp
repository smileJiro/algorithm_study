#include <bits/stdc++.h>

using namespace std;

int N;

int LIS(vector<int> arr)
{
	vector<int> list_LIS;
	list_LIS.push_back(arr[0]);
	for (int num : arr)
	{
		if (list_LIS.back() < num)
		{
			list_LIS.push_back(num);
		}
		else
		{
			auto iter = lower_bound(list_LIS.begin(), list_LIS.end(), num);
			*iter = num;
		}
	}

	return list_LIS.size();
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; ++i)
		cin >> arr[i];


	int answer = LIS(arr);

	cout << answer << '\n';
	return 0;
}