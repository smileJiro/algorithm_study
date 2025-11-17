#include<bits/stdc++.h>

using namespace std;

int Compute369(int _number)
{
	int clapCount = 0;
	int number = _number;
	/* 1. 숫자를 각 자리수별로 분리한다. */
	while (number != 0)
	{
		/* 2. 각 자리 수 별로 3,6,9가 존재하는 지 검사한다. */
		int i = number % 10;
		if (0 == i % 3 && i != 0)
			++clapCount;
		number /= 10;
	}
	/* 3. 모든 자리수 검사 시 박수 횟수를 리턴한다. */
	return clapCount;
}

int main()
{
	int count = 0;
	int clapCount = 0;
	cin >> count;

	for (int i = 1; i < count + 1; i++)
		clapCount += Compute369(i);

	cout << clapCount;
	return 0;
}