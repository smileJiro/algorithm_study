#include<bits/stdc++.h>

using namespace std;


int main()
{
	int n;
	cin >> n;
	list<int> deck;
	int deckSize = 0;
	deck.push_front(n);
	while (deck.size() < n)
	{
		deckSize = deck.size();
		int value = n - deckSize;
		deck.push_front(value);
		for (int i = 0; i < value; ++i)
		{
			// top -> pop -> push_back;
			int tmp = deck.back();
			deck.pop_back();
			deck.push_front(tmp);
		}
	}

	for (int i : deck)
	{
		cout << i << " ";
	}

	return 0;
}