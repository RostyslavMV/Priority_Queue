#pragma once
#include "PriorityQueueInterface.h"
#include "List.h"


template <typename T>
class PriorityQueueList :
	public PriorityQueueInterface <T>
{ 
public:
	virtual void Push(T data, int priority) = 0;
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
