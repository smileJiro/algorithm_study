#include<bits/stdc++.h>
using namespace std;

/* 1. 자연수의 경우 배열자체가 필요가 없다. */
/* 2. 어짜피 연속된 수로 보장되어있으니까 */
//int GetNumberCount_Sum(const vector<int>& _vec, int _target)
//{
//	int count = 0;
//	int left = 0;
//	int right = 0;
//	int sum = 0;
//	while (right < _vec.size())
//	{
//		sum += _vec[right++];
//
//		while (left <= right && _target < sum)
//		{
//			sum -= _vec[left++];
//		}
//
//		if (_target == sum)
//		{
//			++count;
//			sum -= _vec[left++];
//		}
//	}
//	return count;
//}

int GetNumberCount_NaturalSum(int _target)
{
	int count = 0;
	int left = 1;
	int right = 1;
	int sum = 0;
	while (right <= _target)
	{
		sum += right++;

		while (left <= right && _target < sum)
		{
			sum -= left++;
		}

		if (_target == sum)
		{
			++count;
			sum -= left++;
		}
	}
	return count;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int size;
	cin >> size;
	cout << GetNumberCount_NaturalSum(size);

	return 0;
}
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int size;
//	cin >> size;
//	vector<int> vec;
//	vec.resize(size);
//	for (int i = 0; i < size; ++i)
//	{
//		vec[i] = i + 1;
//	}
//
//	cout << GetNumberCount_Sum(vec, size);
//
//	return 0;
//}