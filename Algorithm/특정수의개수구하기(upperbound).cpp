#include<bits/stdc++.h>

using namespace std;

#define SEARCH_FAILED -1

int lowerBound(const vector<int>& arr, int target)
{
	int start(0), end(arr.size() -1);
	int mid(0);

	while (start < end)
	{
		mid = (start + end) >> 1;
		if (arr[mid] < target)
			start = mid + 1;
		else
			end = mid;
	}

	return start;
}

int upperBound(const vector<int>& arr, int target)
{
	int start(0), end(arr.size() -1);
	int mid(0);

	while (start < end)
	{
		mid = (start + end) >> 1;
		if (arr[mid] <= target)
			start = mid + 1;
		else
			end = mid;
	}

	return start;
}

// 이처럼 leftValue와 RightValue 사이의 원소의 개수를 반환하는 함수는 자주 사용된다.
int countByRange(const vector<int>& arr, int left, int right)
{
	vector<int>::const_iterator lower = lower_bound(arr.begin(), arr.end(), left);
	vector<int>::const_iterator upper = upper_bound(arr.begin(), arr.end(), right);
	return upper - lower; // 배열의 연속성을 활용해 iterator 간의 거리를 통해 원소 개수를 카운팅
}

int main()
{
	int n, t;
	cin >> n >> t;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	int numElements = countByRange(arr,t, t);

	cout << numElements << '\n';
	return 0;
}