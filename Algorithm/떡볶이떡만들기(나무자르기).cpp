#include <bits/stdc++.h>

using namespace std;

int getHeight(const vector<int>& arr, int targetLen)
{
	int start = 0;
	int end = *max_element(arr.begin(), arr.end());// 가장 긴 떡의 길이
	int mid = 0;

	int height = 0;
	while (start <= end)
	{
		mid = (start + end) >> 1; // mid == 절단기의 길이 설정 

		long long len = 0;
		for (int i : arr)  // 절단기 기준으로 모든 떡을 잘라보고, 그 잘린 떡의 길이를 모두 합쳐봐
			len += max(0, i - mid);

		if (targetLen <= len) // 잘린 떡의 길이가 목표한 길이보다 길다면 더 절단기를 늘릴 수 있지
		{
			height = mid;
			start = mid + 1;
		}
		else 
			end = mid - 1;

	}

	return height;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int height = getHeight(arr, m);

	cout << height;
	return 0;
}