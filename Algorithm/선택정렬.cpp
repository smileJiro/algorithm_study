#include<bits/stdc++.h>

using namespace std;

void selectSort(vector<int>& array)
{
	int n = array.size();
	for (int i = 0; i < n; ++i)
	{
		int minIdx = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (array[minIdx] > array[j])
				minIdx = j;
		}
		swap(array[i], array[minIdx]);
	}

	for (int i = 0; i < array.size(); ++i)
		cout << array[i] << ' ';
}

int main()
{
	srand(time(nullptr));

	vector<int> array;
	for (int i = 0; i < 100; ++i)
	{
		int value = rand() % 100;
		array.push_back(value);
		cout << value << ' ';
	}
	cout << '\n' << '\n';
	selectSort(array);

	return 0;
}