#include<bits/stdc++.h>

using namespace std;

bool check(int target, int h, int m, int s)
{
	return (target == h % 10 || target == m / 10 || target == m % 10 || target == s / 10 || target == s % 10);
}

int main()
{
	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 0; i <= n; ++i)//시
	{
		for (int j = 0; j < 60; ++j)//분
		{
			for (int k = 0; k < 60; ++k)//초
			{
				if (check(3, i, j, k))//함수안만들고 지역변수 재사용이 낫지 않나
					++cnt;
			}
		}
	}

	cout << cnt << '\n';
	return 0;
}