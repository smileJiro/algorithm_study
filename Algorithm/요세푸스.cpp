#include<bits/stdc++.h>

using namespace std;
//
//void Func(vector<int> array, int k)
//{
//	int arraySize = array.size();
//	vector<int> out;
//	int currentIndex = 0;
//	while (out.size() < array.size())
//	{
//		int count = 0;
//		while (count < k)
//		{
//			if (array[currentIndex % arraySize] != 0)
//			{
//				++count;
//				++currentIndex;
//			}
//			else
//			{
//				++currentIndex;
//			}
//		}
//		out.push_back(array[(currentIndex - 1) % arraySize]);
//		array[(currentIndex - 1) % arraySize] = 0;
//	}
//
//	cout << '<';
//	for (int i = 0; i < out.size(); ++i)
//	{
//		if(i + 1 == out.size())
//			cout << out[i] << ">";
//		else
//			cout << out[i] << ", ";
//	}
//}
//
//int main()
//{
//	int n;
//	int k;
//	cin >> n >> k;
//	vector<int> array(n);
//	for (int i = 0; i < n; ++i)
//		array[i] = i + 1;
//
//	Func(array, k);
//
//
//	return 0;
//}

int main()
{
	int n, k;
	cin >> n >> k;
	queue<int> q;
	for (int i = 0; i < n; ++i)
		q.push(i + 1);


	cout << '<';
	while (1 < q.size())
	{
		for (int i = 0; i < k; ++i) 
		{
			if (i + 1 == k)
				cout << q.front() << ", ";
			else
				q.push(q.front());
			q.pop();
		}
	}
	cout << q.front() << '>';
}