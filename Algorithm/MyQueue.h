#pragma once
struct Node
{
public:
	Node(int value)
		: data(value)
		, next(nullptr)
	{}
public:
	int data;
	Node* next;
};


class MyQueue
{
public:
	MyQueue();
	~MyQueue();

public:
	void enqueue(int value);
	pair<bool, int> dequeue();
	pair<bool, int> peek() const;
	bool isEmpty() const;
	int getSize() const { return size; }

public:
	Node* front = nullptr;
	Node* rear = nullptr;
	int size = 0;
private:
	void initialize();
	void free();
};

