#include<bits/stdc++.h>

using namespace std;
int main()
{
	int ballCount = -1;
	int swapCount = -1;
	cin >> ballCount;
	cin >> swapCount;

	/* 1. 공 채우기 */
	vector<int> vecBalls;
	vecBalls.resize(ballCount);
	for (size_t i = 0; i < vecBalls.size(); ++i)
		vecBalls[i] = i + 1;

	for (int i = 0; i < swapCount; ++i)
	{
		static int srcIdx = -1;
		static int dstIdx = -1;
		cin >> srcIdx;
		cin >> dstIdx;

		swap(vecBalls[srcIdx - 1], vecBalls[dstIdx - 1]);
	}
	
	for (auto& ball : vecBalls)
		cout << ball << " ";
	
	return 0;
}