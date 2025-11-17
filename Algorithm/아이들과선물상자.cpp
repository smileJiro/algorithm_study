#include<bits/stdc++.h>

using namespace std;

void Func(priority_queue<int>& giftBoxes, vector<int>& children)
{
	//sort(children.begin(), children.end(), greater());

	for (int i = 0; i < children.size(); ++i)
	{
		if (giftBoxes.empty())
		{
			cout << '0';
			return;
		}
		
		int tmp = giftBoxes.top() - children[i];
		giftBoxes.pop();
		if (0 > tmp)
		{
			cout << '0';
			return;
		}
		else
			giftBoxes.push(tmp);

		
	}

	cout << 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	priority_queue<int> giftBoxes;
	for (int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;
		giftBoxes.push(input);
	}

	vector<int> children(m);
	for (int i = 0; i < m; ++i)
	{
		int input;
		cin >> input;
		children[i] = input;
	}

	Func(giftBoxes, children);

	return 0;
}