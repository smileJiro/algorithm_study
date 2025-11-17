#pragma once
#include <vector>
using namespace std;
#define INF 1000000000

class MySort
{
public:
	enum SORT_TYPE { SELECTION, BUBBLE, QUICK, INSERT, SHELL, MERGE, LAST };
public:
	MySort();
	~MySort();
public:
	bool		sort(vector<int>& array, SORT_TYPE type);

private:
	bool		selectionSort(vector<int>& array);
	bool		bubbleSort(vector<int>& array);

	bool		quickSortRecursion(vector<int>& array, int start, int end);
	int			quickSortPartition(vector<int>& array, int start, int end);

	bool		insertSort(vector<int>& array);

	bool		shellSort(vector<int>& array);
	bool		shellInsertionSort(vector<int>& array, int start, int end, int interval);

	bool		mergeSort(vector<int>& array, vector<int>& buffer, int start, int end);
	bool		mergeSortInternal(vector<int>& array, vector<int>& buffer, int start, int middle, int end);
};

