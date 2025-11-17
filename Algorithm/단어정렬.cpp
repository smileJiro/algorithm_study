#include<bits/stdc++.h>
#include<unordered_set>

using namespace std;


struct Compare
{
	bool operator() (const string& top, const string& cmp)
	{
		if (top.size() == cmp.size())
			return top < cmp;

		return top.size() < cmp.size();
	}
};
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n;
//	cin >> n;
//
//	priority_queue<string, vector<string>, Compare> pq;
//	unordered_map<string, bool> hashmap;
//	for (int i = 0; i < n; ++i)
//	{
//		string str;
//		cin >> str;
//		if(true != hashmap[str])
//		{
//			pq.push(str);
//			hashmap[str] = true;
//		}
//	}
//
//	while (false == pq.empty()) 
//	{
//		cout << pq.top() << "\n";
//		pq.pop();
//	}
//
//	return 0;
//}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<string> strings;
	unordered_map<string, bool> hashmap;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		if (true != hashmap[str])
		{
			strings.push_back(str);
			hashmap[str] = true;
		}
	}
	sort(strings.begin(), strings.end(), Compare());

	for (auto& out : strings)
	{
		cout << out << "\n";
	}
	return 0;
}