#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int N{}, M{};
int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	unordered_map<string, string> book; 

	
	for (int i = 0; i < N; ++i)
	{
		// 포켓몬 도감 입력
		string num = to_string(i + 1);
		string name;
		cin >> name;
		book.emplace(num, name);
		book.emplace(name, num);
	}
	//cout << "---------------" << '\n';
	for (int i = 0; i < M; ++i)
	{
		// 문제 맞추기
		string key;
		cin >> key;
		cout << book[key] << '\n';
	}

	return 0;
}