#pragma once

template<typename T>
class PriorityItem
{
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
private:
	int size;
public:
	virtual void Push(T data, int priority) = 0;
	virtual void Pop() = 0;
	virtual void Empty() = 0;
	virtual T top() = 0;
	int Size()
	{
		return size;
	}
};