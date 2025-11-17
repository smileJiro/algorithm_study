#include<bits/stdc++.h>

using namespace std;

typedef unsigned int _uint;
struct NumberInfo
{
	_uint value = 0;
	_uint priority = -1;
	short count = 0;
};

bool Compare(const NumberInfo& left, const NumberInfo& right)
{
	if (left.count != right.count)
		return left.count > right.count;

	return left.priority <= right.priority;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// 1. 빈도 해시맵
	// 2. 우선순위 해시맵
	// 3. 결합해서 NumberInfo 배열

	int n, c;
	cin >> n >> c;
	unordered_map<_uint, short> freq; // 빈도
	unordered_map<_uint, _uint> priority; // 우선순위
	_uint priorityCount = 0;
	for (int i = 0; i < n; ++i)
	{
		static _uint input = 0;
		cin >> input;

		if (0 == freq[input])
			priority[input] = priorityCount++;

		++freq[input];
	}

	vector<NumberInfo> finalArray;
	for(auto pair : freq)
	{
		static NumberInfo info{};
		info.value = pair.first;
		info.count = pair.second;
		info.priority = priority[info.value];

		finalArray.push_back(info);
	}

	sort(finalArray.begin(), finalArray.end(), Compare);

	for (auto& numInfo : finalArray)
	{
		for (int i = 0; i < numInfo.count; ++i)
			cout << numInfo.value << " ";
	}
	return 0;
}