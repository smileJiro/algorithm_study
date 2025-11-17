#include <bits/stdc++.h>

using namespace std;
enum {P, L, R, LAST};
struct Node
{
public:
	int node = -1;
	vector<int> arr = {-1,-1,-1};
};
int N;
Node graph[28];
void preOrder(int idx)
{
	if (idx == -1)
		return;

	cout << char(graph[idx].node + 'A' - 1);
	preOrder(graph[idx].arr[L]);
	preOrder(graph[idx].arr[R]);
}
void inOrder(int idx)
{
	if (idx == -1)
		return;

	inOrder(graph[idx].arr[L]);
	cout << char(idx + 'A' - 1);
	inOrder(graph[idx].arr[R]);
}
void postOrder(int idx)
{
	if (idx == -1)
		return;

	postOrder(graph[idx].arr[L]);
	postOrder(graph[idx].arr[R]);
	cout << char(idx + 'A' - 1);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		char sn, sl, sr;
		cin >> sn >> sl >> sr;
		int n{ sn - 'A' + 1 }, l{ sl - 'A' + 1 }, r{sr - 'A' + 1 };
		graph[n].node = n;
		if (l != '.' - 'A' + 1)
		{
			graph[n].arr[L] = l;
			graph[l].arr[P] = n;
		}
		if (r != '.' - 'A' + 1)
		{
			graph[n].arr[R] = r;
			graph[r].arr[P] = n;
		}

	}
		
	preOrder(1);
	cout << '\n';

	inOrder(1);
	cout << '\n';

	postOrder(1);
	cout << '\n';
	return 0;
}