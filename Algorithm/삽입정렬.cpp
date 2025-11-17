#include <bits/stdc++.h>

using namespace std;

void insertSort(vector<int>& array)
{
	int n = array.size();
	for (int i = 1; i < n; ++i)
	{
		int cur = i;
		while (0 < cur && array[cur - 1] > array[cur])
		{
			swap(array[cur - 1], array[cur]);
			--cur;
		}
	}
}
int main()
{
	srand(time(nullptr));
	int n = 10;
	vector<int> array(n);
	for(int& x : array)
	{
		x = rand() % n;
		cout <<  x << ' ';
	}

	cout << '\n';
	cout << '\n';
	insertSort(array);

	for (int x : array)
		cout << x << ' ';

	return 0;
}