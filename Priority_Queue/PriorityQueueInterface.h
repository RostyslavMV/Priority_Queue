#pragma once
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::ostream;

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
	PriorityItem()
	{
	}
	ostream& operator<<(ostream& os)
	{
		os << value;
		return os;
	}
	bool operator==(const PriorityItem& pi)
	{
		return (value == pi.value && priority == pi.priority);
	}
};


template <typename T>
class PriorityQueueInterface
{
public:
	virtual void Push(T data, int priority) = 0;
	virtual void Pop() = 0;
	virtual bool Empty() = 0;
	virtual T Top() = 0;
	virtual	int Size() = 0;
};