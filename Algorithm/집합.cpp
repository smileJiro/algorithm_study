#include <bits/stdc++.h>

using namespace std;

class CMySet
{
public:
	CMySet()
	{}
	~CMySet()
	{}

public:
	void interpret(string str, int i)
	{
		if (str == "add")
			add(i);
		else if (str == "remove")
			remove(i);
		else if (str == "check")
			check(i);
		else if (str == "toggle")
			toggle(i);
		else if (str == "all")
			all();
		else if (str == "empty")
			empty();
	}
public:
	void add(int x)	{ m_set |= 1 << x - 1; }
	void remove(int x) 
	{ 
		unsigned int i = 1 << x - 1;
		if(m_set & i)
			m_set ^= i;
	}
	void check(int x)
	{
		if (m_set & 1 << x - 1)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
	void toggle(int x) { m_set ^= 1 << x - 1; }
	void all() { m_set = (1 << 20) - 1; }
	void empty() { m_set = 0; }

private:
	unsigned int m_set = 0; // 비트연산으로 처리
};
int n = 0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	CMySet set;
	while (n--)
	{
		string str;
		int value = 0;
		cin >> str;
		if (str != "all" && str != "empty")
			cin >> value;
		set.interpret(str, value);
	}
}