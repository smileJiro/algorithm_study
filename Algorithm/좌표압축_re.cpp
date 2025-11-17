#include <bits/stdc++.h>

using namespace std;

int N;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	vector<int> cmpArr(arr);
	sort(cmpArr.begin(), cmpArr.end());
	cmpArr.erase(unique(cmpArr.begin(), cmpArr.end()), cmpArr.end());

	for (int i = 0; i < N; ++i)
	{
		int idx = lower_bound(cmpArr.begin(), cmpArr.end(), arr[i]) - cmpArr.begin();
		cout << idx << ' ';
	}
	return 0;
}