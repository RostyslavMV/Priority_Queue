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
	///
	/// Lower value of priority means higher item priority
	///
	double priority;
	PriorityItem(T value, int priority) 
	{
		this->value = value;
		this->priority = priority;
	}
	///
	/// Default constructor
	///
	PriorityItem()
	{
	}
	///
	/// << operator for an item to output item's value
	///
	ostream& operator<< (ostream& os)
	{
		os << value;
		return os;
	}
	///
	/// Custom == operator
	///
	bool operator==(const PriorityItem& pi)
	{
		return (value == pi.value && priority == pi.priority);
	}
	///
	/// > operator for comparing by value
	///
	bool operator>(const PriorityItem& pi)
	{
		return (value > pi.value);
	}
};

template<typename T>
class PriorityTreeItem: public PriorityItem<T>
{
public:
	///
	/// Constructor for ordinary usage
	///
	PriorityTreeItem(T value, double priority)
	{
		this->value = value;
		this->priority = priority;
	}
	///
	/// Default constructor
	///
	PriorityTreeItem()
	{
	}
	///
	/// > operator to compare by priority
	///
	bool operator>(const PriorityTreeItem& pi)
	{
		return (this->priority > pi.priority);
	}
};


template <typename T>
class PriorityQueueInterface
{
public:
	virtual void Push(T data, double priority) = 0;
	virtual void Pop() = 0;
	virtual bool Empty() = 0;
	virtual T Top() = 0;
	virtual	int Size() = 0;
};