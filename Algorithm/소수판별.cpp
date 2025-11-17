#include <bits/stdc++.h>

using namespace std;

// 소수란 1과 자기 자신을 제외한 자연수로는 나누어떨어지지 않는 자연수

bool isPrime(int n)
{
	for (int i = 2; i < n; ++i)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

bool isPrime2(int n) // 약수의 특성을 활용 -> 제곱 근까지만 확인해도 돼 약수란 대칭을 이루니까
{
	int x = sqrt(n);
	for (int i = 2; i <= x; ++i)
	{
		if (n % x == 0)
			return false;
	}

	return true;
}

void isPrime3(vector<bool>& arr) // 에라토스테네스의 체 알고리즘
{
	int n = arr.size() - 1;
	int sqrtN = sqrt(n);
	for (int i = 2; i <= sqrtN; ++i)
	{
		if (arr[i] == true)
		{
			int mul = 2;
			while (i * mul <= n)
				arr[i * mul++] = false;
		}

	}

	for (int i = 2; i <= n; ++i)
		if (arr[i] == true)
			cout << i << ' ';
}
int main()
{
	//if (isPrime(12))
	//	cout << "is Prime" << '\n';
	//else
	//	cout << "is not Prime" << '\n';

	int n;
	cin >> n;
	n += 1;
	vector<bool> arr(n, true);
	isPrime3(arr);


	return 0;
}