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
	void Empty() {
		if (this->Size() == 0) return true;
		else
		{
			return false;
		}
	}
	virtual T Top() = 0;
};
