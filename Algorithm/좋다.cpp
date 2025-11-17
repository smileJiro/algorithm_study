//#include<bits/stdc++.h>
#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

bool Is_Sum(const vector<int>& _vec, int _target, unsigned int _curIndex)
{
	int left = 0, right = _vec.size() - 1;
	int sum;

	while (left < right)
	{
		if (_curIndex == left)
		{
			++left;
			continue;
		}
		if (_curIndex == right)
		{
			--right;
			continue;
		}

		sum = _vec[left] + _vec[right];

		if (sum == _target)
			return true;
		else if (sum > _target)
			--right;
		else if (sum < _target)
			++left;
	}

	return false;
}

//int main()
//{
//	int N;
//	cin >> N;
//	vector<int> vec(N);
//	
//	for (int i = 0; i < N; ++i)
//		cin >> vec[i];
//
//	/* 1. 정렬 먼저 하고 */
//	sort(vec.begin(), vec.end());
//
//	/* 2. 탐색 시작 */
//	int count = 0;
//	for (int i = 0; i < vec.size(); ++i)
//	{
//		if (true == Is_Sum(vec, vec[i], i))
//			++count;
//	}
//	cout << count << "\n";
//
//	return 0;
//}


/* 1. 반복문 루프 도는데. 0,1 인덱스는 패스하고 2번 인덱스부터 돈다. */

/* 2. left = 0; right = currentloopindex - 1; */

/* 3. 투포인터 돌리면서 합 결과 찾는데 단 하나만 찾아도 true 리턴한다. */


bool Is_Sum_Hash(const vector<int>& _vec, int _target, unsigned int _curIndex)
{
	unordered_set<int> uset;

	for (int i = 0; i < _vec.size(); ++i)
	{
		if (_curIndex == i)
			continue;

		uset.insert(_target - _vec[i]);
		if (uset.find(_vec[i]) != uset.end())
			return true;

	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	vector<int> vec(N);

	for (int i = 0; i < N; ++i)
		cin >> vec[i];

	
	/* 2. 탐색 시작 */
	int count = 0;
	for (int i = 0; i < vec.size(); ++i)
	{
		if (true == Is_Sum_Hash(vec, vec[i], i))
			++count;
	}
	cout << count << "\n";
	return 0;
}