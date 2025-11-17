#include"pch.h"
#include "MyQueue.h"

int main()
{
	MyQueue q;

	for (int i = 0; i < 100; ++i)
	{
		q.enqueue(i);
	}
	int a = q.getSize();
	for (int i = 0; i < 90; ++i)
	{
		pair<bool, int> pair = q.dequeue();
	}

	if (true == q.isEmpty())
	{
		int a = 0;
	}


	return 0;
}