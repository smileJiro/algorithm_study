#include<bits/stdc++.h>

using namespace std;

int Compute_SumCount(const vector<int>& _vec, int _target)
{
	int count{}, left{}, right{}, sum{};
	right = _vec.size() - 1;

	while (left < right)
	{
		sum = _vec[left] + _vec[right];
		
		if (sum == _target)
		{
			++count;
			++left; 
			--right;
		}
		else if (sum > _target)
		{
			--right;
		}
		else if (sum < _target)
		{
			++left;
		}
	}

	return count;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> vecNums{};
	/* input */
	int numCount;
	cin >> numCount;
	vecNums.resize(numCount);
	for (int i = 0; i < vecNums.size(); ++i)
	{
		cin >> vecNums[i];
	}
	int target;
	cin >> target;

	/* 1. 정렬(오름차순) */
	sort(vecNums.begin(), vecNums.end());
	/* 2. 두 수의 합 탐색 */
	cout << Compute_SumCount(vecNums, target) << "\n";


	return 0;
}