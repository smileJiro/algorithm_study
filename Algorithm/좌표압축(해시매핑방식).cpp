#include <bits/stdc++.h>

using namespace std;

int N;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	int num = 0;
	vector<int> arr(N);
	
	
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	vector<int> sortArr = arr;
	sort(sortArr.begin(), sortArr.end());
	sortArr.erase(unique(sortArr.begin(), sortArr.end()), sortArr.end()); // 중복 제거

	int sortSize = sortArr.size();
	unordered_map<int, int> hash;
	for (int i = 0; i < sortSize; ++i)
		hash[sortArr[i]] = i;

	for (int i = 0; i < N; ++i)
		cout << hash[arr[i]] << ' ';

	return 0;
}