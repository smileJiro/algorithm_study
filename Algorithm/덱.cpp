#include <bits/stdc++.h>

using namespace std;

typedef unsigned int _uint;
#pragma region MyDeque

class MyDeque
{
public:
	MyDeque() {};
	~MyDeque() {};

public:
	void InterpretCommands(string str) {
		if ("push_back" == str)
		{
			cin >> input;
			PushBack(input);
		}
		else if ("push_front" == str)
		{
			cin >> input;
			PushFront(input);
		}
		else if ("pop_front" == str)
			PopFront();
		else if ("pop_back" == str)
			PopBack();
		else if ("size" == str)
			Size();
		else if ("empty" == str)
			Empty();
		else if ("front" == str)
			Front();
		else if ("back" == str)
			Back();
	}
private:
	void	PushFront(int value) { datas.push_front(value); }
	void	PushBack(int value) { datas.push_back(value); }
	void	Size() { Output(datas.size()); }
	void	PopFront() {
		if (datas.empty())
		{
			Output(-1);
			return;
		}
		Output(datas.front());
		datas.pop_front();
	}
	void	PopBack() {
		if (datas.empty())
		{
			Output(-1);
			return;
		}
		Output(datas.back());
		datas.pop_back();
	}
	void	Empty() {
		Output(datas.empty());
	}
	void	Front() {
		if (datas.empty())
		{
			Output(-1);
			return;
		}
		Output(datas.front());
	}
	void	Back() {
		if (datas.empty())
		{
			Output(-1);
			return;
		}
		Output(datas.back());
	}
	void	Output(int output) { cout << output << "\n"; }


private:
	list<int> datas;
	int input = 0;
};
#pragma endregion


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	MyDeque myDeque;
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		myDeque.InterpretCommands(str);
	}
	return 0;
}