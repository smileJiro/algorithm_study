#include "MySort.h"

MySort::MySort()
{
}

MySort::~MySort()
{
}

bool MySort::sort(vector<int>& array, SORT_TYPE type)
{
	bool result = false;
	switch (type)
	{
	case MySort::SELECTION:
		result = selectionSort(array);
		break;
	case MySort::BUBBLE:
		result = bubbleSort(array);
		break;
	case MySort::QUICK:
		if(1 < array.size())
			result = quickSortRecursion(array, 0, array.size() - 1);
		break;
	case MySort::INSERT:
		result = insertSort(array);
		break;
	case MySort::SHELL:
		result = shellSort(array);
		break;
	case MySort::MERGE:
	{
		vector<int> buffer(array.size());
		result = mergeSort(array, buffer, 0, array.size() - 1);
	}
		break;
	default:
		break; 
	}

    return result;
}

bool MySort::selectionSort(vector<int>& array)
{
	///* 오름 차순 정렬 */
	//for (int i = 0; i < array.size(); ++i)
	//{
	//	/* 1. i부터 시작해서 가장 작은 수를 탐색한다. */
	//	int minimumIdx = -1;
	//	int minimum = array[i];
	//	for (int j = i + 1; j < array.size(); ++j)
	//	{
	//		if (minimum > array[j])
	//		{
	//			minimum = array[j];
	//			minimumIdx = j;
	//		}
	//	}
	//	array[minimumIdx] = array[i];
	//	array[i] = minimum;
	//}

	for (int i = 0; i < array.size(); ++i)
	{
		int minIndex = i;
		for (int j = i + 1; j < array.size(); ++j)
		{
			if (array[j] < array[minIndex])
			{
				minIndex = j;
			}
		}

		if (i != minIndex)
		{
			swap(array[i], array[minIndex]);
		}
	}

    return true;
}

bool MySort::bubbleSort(vector<int>& array)
{
	int size = array.size();
	for (int i = 0; i < size; ++i)
	{
		bool swapped = false;
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				swap(array[j], array[j + 1]);
				swapped = true;
			}
		}

		/* 만약 한번의 정렬조차 발생하지 않았다면, 이건 이미 정렬 되어있다는 것 */
		if (false == swapped)
			break;
	}





	for (int i = array.size() -1; i >= 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (array[j] > array[j+1])
			{
				swap(array[j], array[j+1]);
			}
		}
	}

	return true;
}

bool MySort::quickSortRecursion(vector<int>& array, int start, int end)
{
	int pivot = 0;
	// 탈출 조건
	if (start < end)
	{
		pivot = quickSortPartition(array, start, end);
		quickSortRecursion(array, start, pivot - 1);
		quickSortRecursion(array, pivot + 1, end);
	}

	return true;
}

/* 퀵 정렬를 수행하고 새로운 피봇과 배열을 리턴한다. */
int MySort::quickSortPartition(vector<int>& array, int start, int end)
{
	int left(start), right(end), pivot(end);
	// 1. left와 right가 같아질 때 까지 루프를 수행한다.
	while (left < right)
	{
		bool leftResult(false), rightResult(false);
		// 2. left는 pivot보다 큰 값을 찾는다.
		while (array[pivot] > array[left] && 
			left < right)
			++left;

		// 3. right는 pivot보다 작은 값을 찾는다.
		while (array[pivot] <= array[right] &&
			left < right)
			--right;

		// 4. left와 right가 결정되면 교환을 수행한다.
		if (left < right)
		{
			swap(array[left], array[right]);
		}
	}

	// 루프를 탈출하면 탈출 후 left == right 값이 새로운 pivot이 된다.
	swap(array[left], array[pivot]);
	pivot = left;
	return pivot;
}

bool MySort::insertSort(vector<int>& array)
{
	int n = array.size();
	
	//for (int i = 1; i < n; ++i)				/* 1. 삽입 대상 인덱스 */
	//{
	//	bool insert = false;
	//	auto iter = array.begin();
	//	int tmp = 0;
	//	for (int j = i - 1; j >= 0; --j)	/* 2. 검사 대상 인덱스 */
	//	{
	//		if (array[j] < array[i])		/* 3. 삽입 대상 값보다 작은 값을 만난다면,*/
	//		{
	//			/* 4. j + 1 인덱스에 데이터를 삽입해야한다. */
	//			insert = true;
	//			tmp = array[i];
	//			array.erase(iter + i);
	//			array.insert(iter + j + 1, tmp);
	//			break;
	//		}
	//	}
	//	if (false == insert)
	//	{
	//		/* 5. 삽입이 발생하지 않았다면 가장 작은 값이란 의미 */
	//		tmp = array[i];
	//		array.erase(iter + i);
	//		array.insert(iter, tmp);
	//	}
	//	
	//}

	for (int i = 1; i < n; ++i)
	{
		int key = array[i]; // 현재 삽입 대상 값
		int j = i - 1; // 비교 대상 인덱스

		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			--j;
		}
		array[j + 1] = key;
	}


	return true;
}

bool MySort::shellSort(vector<int>& array)
{
	int n = array.size();
	int interval = n / 2;

	while (1 <= interval) // 인터벌이 1보다 작거나 같을때 까지 루프.
	{
		for (int i = 0; i < interval; ++i) // 
		{
			shellInsertionSort(array, i, n - 1, interval);
		}

		interval = interval / 2;
	}
	

	return true;
}

bool MySort::shellInsertionSort(vector<int>& array, int start, int end, int interval)
{
	int i = 0;
	int item = 0;
	int idx = 0;

	for (int i = start + interval; i <= end; i = i + interval)
	{
		item = array[i];
		idx = i - interval;
		while (idx >= start && item < array[idx])
		{
			array[idx + interval] = array[idx];
			idx = idx - interval;
		}
		array[idx + interval] = item;
	}


	

	return true;
}

bool MySort::mergeSort(vector<int>& array, vector<int>& buffer, int start, int end)
{
	/* 1. 원소의 개수가 1개가 될 때까지 순환적으로 병합 정렬을 실행한다. */
	int middle = 0;
	if (start < end)
	{
		/* 2. 2개의 부분 집합으로 나누기 위해 중간 위치인 middle을 구한다. */
		middle = (start + end) / 2;

		/* 3. 왼쪽 부분 집합(start ~ middle)과 오른 쪽 부분 집합(middle+1 ~ end)에 대해 재귀적으로 병합 정렬을 실행 한다 */
		mergeSort(array, buffer, start, middle);
		mergeSort(array, buffer, middle + 1, end);

		/* 4. 병합 정렬이 완료 된 두개의 부분집합에 대해 병합을 실시한다. */
		/* 단, 이때 병합을 위해 배열의 개수만큼 추가적인 메모리 공간이 필요하고, 이를 위해 buffer를 전달한다. */
		mergeSortInternal(array, buffer, start, middle, end);
	}


	return true;
}

bool MySort::mergeSortInternal(vector<int>& array, vector<int>& buffer, int start, int middle, int end)
{
	/* i : 처번째 부분 집합의 원소를 가리키는 인덱스 j : 두번째 부분 집합의 원소를 가리키는 인덱스 */
	int i = start, j = middle + 1;
	/* k : 결과 버퍼의 현재 위치를 가리키는 인덱스 */
	int k = start, t = 0;
	
	while (i <= middle && j <= end)
	{
		if (array[i] <= array[j])
			/* 첫 부분 집합의 원소를 가리키는 i 번째 인덱스의 값이 더 작다면, */
			buffer[k] = array[i++];
		else
			buffer[k] = array[j++];

		++k;
	}

	/* 위 루프를 모두 빠져나왔다는 것은 한개의 부분 집합에 대해서는 모두 정렬 후 buffer에 복사가 완료 되었다는 의미
	하지만 아직 다른 한쪽의 데이터에 대해서는 복사 되지 않은 데이터가 있다는 거야 남은 원소를 마저 복사 */
	if (i > middle)
	{
		/* 좌측 부분집합이 모두 복사되었다는 의미 >>> 우측 부분집합의 남은 값을 마저 복사*/
		for (t = j; t <= end; ++t, ++k)
			buffer[k] = array[t];
	}
	else
	{
		/* 우측 부분 집합이 모두 복사되었다는 의미 >>> 남아 있는 좌측 부분집합을 마저 복사 */
		for (t = i; t <= middle; ++t, ++k)
			buffer[k] = array[t];
	}

	/* 결과물로 나온 buffer를 array에 복사 */

	for (t = start; t <= end; ++t)
	{
		array[t] = buffer[t];
	}
	
	return true;
}
