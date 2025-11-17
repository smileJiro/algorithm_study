#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);
	int sum{};
	int result{};
	for (int i = 0; i < N; ++i)
	{
		sum += arr[i]; // 대기 시간 
		result += sum;
	}

	cout << result;
	return 0;
}