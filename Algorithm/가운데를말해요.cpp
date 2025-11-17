#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	priority_queue<int, vector<int>, greater<int>> minHeap;
	priority_queue<int> maxHeap;

	int inputCount;
	cin >> inputCount;
	for (int i = 0; i < inputCount; ++i)
	{
		int inputNum;
		cin >> inputNum;

		if (maxHeap.empty() || inputNum <= maxHeap.top())
			maxHeap.push(inputNum);
		else
			minHeap.push(inputNum);

		/* ¸®¹ë·±½Ì Å×½ºÆ® */

		if (maxHeap.size() < minHeap.size())
		{
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
		else if(maxHeap.size() > minHeap.size() + 1)
		{
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		}

		cout << maxHeap.top() << "\n";
	}

	return 0;
}
