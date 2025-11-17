#include <bits/stdc++.h>

using namespace std;

int getCountTargetSum(vector<int>& arr, int target)
{
	int sum{0}, s{0}, e{0}, count{0};
	int n = arr.size();
	for (; s < n; ++s)
	{
		while (sum < target && e < n)
			sum += arr[e++];

		if (sum == target)
			++count;

		sum -= arr[s];
	}

	return count;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	cout << getCountTargetSum(arr, m) << '\n';

	return 0;
}