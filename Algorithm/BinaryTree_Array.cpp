#include "BinaryTree_Array.h"

BinaryTree_Array::BinaryTree_Array()
{
	/* push_back dummy */
	m_arrayNodes.push_back(nullptr);
}

BinaryTree_Array::~BinaryTree_Array()
{
}

int BinaryTree_Array::getRootNode()
{
	if (1 >= m_arrayNodes.size())
		assert(nullptr);

	return m_arrayNodes[ROOT];
}

bool BinaryTree_Array::insert(int value)
{
	
	m_arrayNodes.push_back(value);
	return false;
}