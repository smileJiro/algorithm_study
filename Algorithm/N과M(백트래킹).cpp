#include <bits/stdc++.h>

using namespace std;

void BT(vector<int>& arr, vector<bool>& used, int depth)
{
	if (depth == arr.size())
	{
		for (int i = 0; i < arr.size(); ++i)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	int n = used.size();
	for (int i = 1; i < n; ++i)
	{
		if (used[i] == false)
		{
			used[i] = true;
			arr[depth] = i;
			BT(arr, used, depth + 1);
			used[i] = false;
		}
	}

	return;
}
int main()
{
	int n, m; // 1 ~ n 까지의 수, 수열의 길이
	cin >> n >> m;

	vector<bool> used(n + 1, false);
	vector<int> arr(m);

	BT(arr, used, 0);
	return 0;
}