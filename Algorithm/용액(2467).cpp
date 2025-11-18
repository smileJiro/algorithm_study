#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100002];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	// 투포인터 풀이
	int l{0}, r{N - 1};
	int minL{l}, minR{r};
	int minValue = abs(arr[l] + arr[r]);
	while (l < r)
	{
		int sum = arr[l] + arr[r];
		if (abs(sum) <= minValue)
		{
			minValue = abs(sum);
			/*cout <<"minValue : " << minValue << '\n';*/
			minL = l;
			minR = r;
			if (0 == sum)
				break;
		}

		if (0 < sum)
			--r;
		else if (0 > sum) // 음수
			++l;

	}

	cout << arr[minL] << ' ' << arr[minR];
	return 0;
}
// 디버깅 노트
// minValue = 1e9로 설정했던게 문제였어
// 만약 10억, 10억 두 용액이 있으면 처음부터 이 두용액이 만드는 20억이 최소 합인데
// 이게 선택이 안되는거야 