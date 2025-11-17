#include<bits/stdc++.h>

using namespace std;

#define SEARCH_FAILED -1

int binarySearch(const vector<int>& arr, int target)
{
	int start(0), end(arr.size() - 1);
	int center = (end + start) >> 1;
	while (start <= end)
	{
		center = (end + start) >> 1;
		if (arr[center] == target)
			return center;

		arr[center] < target ? start = center + 1 : end = center - 1;
	}

	return SEARCH_FAILED;
}
int main()
{
	srand(time(nullptr));

	int n, m, target;

	cin >> n >> m >> target;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		arr[i] = rand() % m;

	sort(arr.begin(), arr.end());

	int result = binarySearch(arr, target);
	if (SEARCH_FAILED == result)
		cout << "Failed" << '\n';
	else
		cout << "Index : " << result << '\n';
	

	return 0;
}