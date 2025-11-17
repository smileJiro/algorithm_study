#include "pch.h"

#define DUMMY 1
#define QUEUE_MAX (10 + DUMMY)

typedef struct tagCircularQueue
{
public:
	bool Enqueue(int _i)
	{
		int next = nextpos(rear);
		if (next == front)
			return false;

		rear = next;
		array[rear] = _i;
		return true;
	};
	bool Dequeue(int* _out = nullptr)
	{
		if (true == empty())
			return false;

		front = nextpos(front);
		if(nullptr != _out)
			*_out = array[front];
		return true;
	};
	bool peek(int* _out) 
	{
		if (empty())
			return false;

		*_out = array[nextpos(front)];
		return true;
	};


	
public:
	int nextpos(int _cur) {	return (_cur + 1) % QUEUE_MAX; }
	int full() 	{ return nextpos(rear) == front; }
	bool empty() { return front == rear; }
	int size() { return (rear + QUEUE_MAX - front) % QUEUE_MAX; }
	void clear() { front = rear = 0; }
	void print_all() 
	{
		int cur = front;
		while (cur != rear)
		{
			cur = nextpos(cur);
			std::cout << array[cur] << "\n";
		}
	}

public:
	int front = 0;
	int rear = 0;
	int array[QUEUE_MAX];
}CIRCULAR_QUEUE;
int main()
{
	CIRCULAR_QUEUE q;

	for (int i = 0; i < 10; ++i)
	{
		if (false == q.Enqueue(i + 1))
			assert(nullptr);

	}
	for (int i = 0; i < 12; ++i)
	{
		if (false == q.Dequeue(nullptr))
			assert(nullptr);
		if (false == q.Enqueue(i + 11))
			assert(nullptr);

	}

	if (q.full())
	{
		int a = 0;
	}
	if (q.empty())
	{
		int a = 0;
	}
	int size = q.size();
	int peek;
	q.peek(&peek);
	q.print_all();
	int deq;
	q.Dequeue(&deq);

	q.clear();
	if (q.empty())
	{
		int a = 0;
	}
	return 0;

}