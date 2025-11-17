#include "pch.h"
#include "MyQueue.h"

MyQueue::MyQueue()
{
	initialize();
}

MyQueue::~MyQueue()
{
	free();
}

void MyQueue::enqueue(int value)
{
	Node* newNode = new Node(value);

	if (true == isEmpty())
	{
		/* front 의 next*/
		front = newNode;
		rear = newNode;
	}
	else
	{
		rear->next = newNode;
		rear = newNode;
	}
	++size;
}

pair<bool, int> MyQueue::dequeue()
{
	pair<bool, int> out;
	if (true == isEmpty())
		out.first = false;
	else 
	{
		/* 1. front 값을 리턴 */
		out.first = true;
		out.second = front->data;

		/* 2. 후처리 (front를 next로 변경) */
		Node* deleteNode = front;
		front = front->next;
		delete deleteNode;

		/* 3. emtpy 상태가 되었다면 rear도 댕글링 포인터 처리 */
		if (front == nullptr)
			rear = nullptr;

		--size;
	}

	return out;
}

pair<bool, int> MyQueue::peek() const
{
	pair<bool, int> out;
	if (true == isEmpty())
		return { false, -1 };
	else
	{
		out.first = true;
		out.second = front->data;
	}

	return out;
}

bool MyQueue::isEmpty() const
{
	return nullptr == front;
}

void MyQueue::initialize()
{
}

void MyQueue::free()
{
	if (nullptr != front)
		delete front;
	if (nullptr != rear)
		delete rear;
}
