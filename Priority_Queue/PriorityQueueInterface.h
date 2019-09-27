#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

template<typename T>
class PriorityItem
{
public:
	T value;
	int priority;
	PriorityItem(T value, int priority) 
	{
		this->value = value;
		this->priority = priority;
	}
};


template <typename T>
class PriorityQueueInterface
{
public:
	virtual void Push(T data, int priority) = 0;
	virtual void Pop() = 0;
	virtual bool Empty() = 0;
	virtual T top() = 0;
	virtual	int Size() = 0;
};