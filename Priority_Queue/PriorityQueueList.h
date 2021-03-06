#pragma once
#include "PriorityQueueInterface.h"
#include "List.h"

using std::out_of_range;

///
/// Interface for PriorityQueueArrayList and PriorityQueueLinkedList
///
template <typename T>
class PriorityQueueList :
	public PriorityQueueInterface <T>
{ 
protected:

public:
	virtual void Push(T data, double priority) = 0;
	virtual void Pop() = 0;
	virtual T Top() = 0;
	bool Empty() override {
		if (this->Size() == 0) return true;
		else
		{
			return false;
		}
	}
};
