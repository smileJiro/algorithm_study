#include<bits/stdc++.h>

using namespace std;


int Sum(const vector<int>& _vec, int _target)
{
	int count{}, sum{}, left{}, right{};

	while (right <= _vec.size())
	{
		if (sum == _target)
		{
			++count;
			sum -= _vec[left];
			++left;
		}
		else if (sum < _target)
		{
			if (right == _vec.size())
				break;

			sum += _vec[right];
			++right;
		}
		else if (sum > _target)
		{
			sum -= _vec[left];
			++left;
		}
		else
		{

		}
	}

	return count;
}

/* ÀÌ°Ô ´õ ±ò²û */
int Sum2(const vector<int>& _vec, int _target)
{
	int count{}, sum{}, left{}, right{};

	while (right < _vec.size())
	{
		sum += _vec[right];
		++right;

		while (left <= right && sum > _target)
		{
			sum -= _vec[left];
			++left;
		}

		if (sum == _target)
		{
			++count;
			sum -= _vec[left];
			++left;
		}
	}

	return count;
}
int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> vec = { 1,3,6,5,2,7,9 };

	cout << Sum2(vec, 9);


	return 0;
}