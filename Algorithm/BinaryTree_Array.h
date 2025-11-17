#pragma once
#include <assert.h>
#include <vector>

#define ROOT 1

class BinaryTree_Array
{
public:
	BinaryTree_Array();
	~BinaryTree_Array();

public:

public:
	int						getRootNode();
	
	bool					insert(int value);
private:
	std::vector<int>		m_arrayNodes;
};

