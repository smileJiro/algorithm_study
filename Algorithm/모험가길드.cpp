#include <bits/stdc++.h>

using namespace std;


int main()
{
	int n;
	cin >> n;

	vector<int> horrors(n);
	for (int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;
		horrors[i] = input;
	}

	sort(horrors.begin(), horrors.end());

	int result = 0;
	int currentCnt = 0;
	for (int i = 0; i < n; ++i)
	{ 
		currentCnt += 1; // 모험가 추가
		if (currentCnt >= horrors[i])
		{
			result += 1;
			currentCnt = 0;
		}
	}

	cout << result << '\n';
	return 0;
}