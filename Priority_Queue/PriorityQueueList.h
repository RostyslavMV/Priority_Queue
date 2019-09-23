#pragma once
#include "PriorityQueueInterface.h"

template <typename T>

class PriorityQueueList :
	public PriorityQueueInterface <T>
{
public:
	virtual void Push() override;
	virtual void Pop() override;
	virtual void Empty() override;
	virtual T top() override;
};

