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
	unordered_map<int,int> hash;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	// 1. 오름차순 정렬
	vector<int> compArr = arr;
	sort(compArr.begin(), compArr.end());
	// 2. 중복 원소 뒤로 미루기 + 미뤄둔 원소들 삭제하기
	compArr.erase(unique(compArr.begin(), compArr.end()), compArr.end());

	// 3. 이분탐색으로 인덱스 찾기
	for (int i = 0; i < N; ++i)
	{
		int idx = lower_bound(compArr.begin(), compArr.end(), arr[i]) - compArr.begin();
		cout << idx << '\n';
	}

	return 0;
}