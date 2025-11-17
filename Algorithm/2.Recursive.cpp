#include <stdio.h>
#include <iostream>

using namespace std;

int Factorial(int _n)
{
	if (_n == 0)
		return 1;

	return _n * Factorial(_n - 1);
}

int Fibo(int _n, int _level = 0, int LR = -1)
{
	if(LR == 0)
		cout << _level << " >>> L " << "\n";
	else if (LR == 1)
		cout << _level << " >>> R " << "\n";
	else
		cout << _level << " >>> First Call" << "\n";


	if (1 == _n)
	{
		cout << " 1 Å»Ãâ" << "\n";
		return 0;
	}
	else if (2 == _n)
	{
		cout << " 2 Å»Ãâ" << "\n";
		return 0;
	}

	return Fibo(_n - 2, _level + 1, 0) + Fibo(_n - 1, _level + 1, 1);
}

int BinarySearch_ReCursive(int* _arr, int _firstIdx, int _lastIdx, int _targetNum)
{
	int midIdx = -1;
	if (_firstIdx > _lastIdx)
		return -1;
	midIdx = (_firstIdx + _lastIdx) / 2;

	if (_targetNum == _arr[midIdx])
		return midIdx;
	else if (_targetNum < _arr[midIdx])
		BinarySearch_ReCursive(_arr, _firstIdx, midIdx - 1, _targetNum);
	else
		BinarySearch_ReCursive(_arr, midIdx + 1, _lastIdx, _targetNum);
}
int main()
{
	//cout << Factorial(1) << "\n";
	//cout << Factorial(2) << "\n";
	//cout << Factorial(3) << "\n";
	//cout << Factorial(4) << "\n";
	//cout << Factorial(9) << "\n";
	//
	//
	//cout << Fibo(1) << "\n";
	//cout << Fibo(2) << "\n";
	//cout << Fibo(3) << "\n";
	//cout << Fibo(4) << "\n";
	//cout << Fibo(5) << "\n";
	//cout << Fibo(6) << "\n";
	//cout << Fibo(7) << "\n";
	//cout << Fibo(9) << "\n";
	//cout << Fibo(7) << "\n";


	int arr[] = { 1,3,5,7,9,13,17,24 };
	int idx = -1;

	idx = BinarySearch_ReCursive(arr, 0, sizeof(arr) / sizeof(int) - 1, 15);
	if (-1 == idx)
		printf("Failed Search \n");
	else
		printf("Serch Index : %d \n", idx);
	return 0;
}