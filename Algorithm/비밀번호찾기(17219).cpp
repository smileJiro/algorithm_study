#include <bits/stdc++.h>

using namespace std;

int N, M;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	unordered_map<string, string> sites;
	string name, password;
	for (int i = 0; i < N; ++i) // 사이트, 비밀번호 저장
	{
		cin >> name >> password;
		sites[name] = password;
	}

	for (int i = 0; i < M; ++i)
	{
		cin >> name;
		cout << sites[name] << '\n';
	}
	return 0;
}