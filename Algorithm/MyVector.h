#pragma once
#include<cstring>
#include<stdio.h>

template<typename T>
class MyVector
{
public:
	MyVector();
	~MyVector();

private:
	void Initialize();
	void Free();

public:
	void Push_back(const T& _data);
	void Resize(unsigned int _numResize);
	void Erase(unsigned int _idx);
public:
	unsigned int Size() { return m_size; }
	unsigned int Capacity() { return m_capacity; }

public:
	T& operator [](unsigned int _idx)
	{
		return m_array[_idx];
	}
private:
	T* m_array = nullptr;
	unsigned int m_size = {};
	unsigned int m_capacity = {};
};

template<typename T>
inline MyVector<T>::MyVector()
{
	Initialize();
}

template<typename T>
inline MyVector<T>::~MyVector()
{
	Free();
}

template<typename T>
inline void MyVector<T>::Initialize()
{
}

template<typename T>
inline void MyVector<T>::Free()
{
	if (nullptr != m_array)
		delete[] m_array;
}

template<typename T>
inline void MyVector<T>::Push_back(const T& _data)
{
	if (m_size >= m_capacity)
		Resize(m_capacity + m_capacity / 2 + 1);
	
	m_array[m_size++] = _data;
}

template<typename T>
inline void MyVector<T>::Resize(unsigned int _numResize)
{
	/* 1. 새로운 배열을 동적할당 */
	T* newArray = new T[_numResize];

	/* 2. 기존의 배열의 데이터를 새로 할당한 배열에 이전 */
	if(nullptr != m_array)
	{
		std::copy(m_array, m_array + m_size, newArray);
		delete[] m_array;
	}

	/* 3. 포인터 교체 */
	m_array = newArray;
	m_capacity = _numResize;
}

template<typename T>
inline void MyVector<T>::Erase(unsigned int _idx)
{
	if (m_size <= _idx)
		return;

	for (int i = _idx; i < m_size - 1; ++i)
	{
		m_array[i] = m_array[i + 1];
	}
	--m_size;
	
}

