#include <stdio.h>

int BinarySearch(int _arr[], int _len, int _targetNum)
{
	int firstIdx = 0;
	int lastIdx = _len - 1;
	int midIdx;

	while (firstIdx <= lastIdx)
	{
		midIdx = (firstIdx + lastIdx) / 2;
		printf("Current midIdx : %d \n", midIdx);
		if (_targetNum == _arr[midIdx])
			return midIdx;
		else
		{
			/* 탐색 대상을 반으로 줄인다. */
			if (_targetNum < _arr[midIdx])
				lastIdx = midIdx -1;
			else
				firstIdx = midIdx +1;
		}
	}

	return -1;
}



int main()
{
	int arr[] = { 1,3,5,7,9,13,17,24 };
	int idx = -1;

	idx = BinarySearch(arr, sizeof(arr)/ sizeof(int), 24);
	if (-1 == idx)
		printf("Failed Search \n");
	else
		printf("Serch Index : %d \n", idx);

	idx = BinarySearch(arr, sizeof(arr) / sizeof(int), 4);
	if (-1 == idx)
		printf("Failed Search \n");
	else
		printf("Serch Index : %d \n", idx);

	return 0;
}