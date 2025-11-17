#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

struct NumCount
{
	int count;
	int priority;
};

struct Compare
{
	bool operator()(const pair<int, NumCount>& top, const pair<int, NumCount>& cmp)
	{
		if (top.second.count != cmp.second.count)
			return top.second.count < cmp.second.count;
		else
			return top.second.priority > cmp.second.priority;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, c;
	cin >> n >> c;

	unordered_map<int, NumCount> umap;
	int priorityCount = 0;
	for (int i = 0; i < n; ++i)
	{
		static int input;
		cin >> input;
		if (0 == umap[input].count)
			umap[input].priority = priorityCount++;
		umap[input].count++;
	}

	priority_queue<pair<int, NumCount>, vector<pair<int, NumCount>>, Compare> pq;
	
	for (auto& pair : umap)
	{
		pq.push(pair);
	}

	while (!pq.empty())
	{
		for (int i = 0; i < pq.top().second.count; ++i) 
		{
			cout << pq.top().first << " ";
		}
		pq.pop();
	}
	
	return 0;
}