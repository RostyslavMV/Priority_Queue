#pragma once
#include "PriorityQueueInterface.h"
#include "List.h"


template <typename T>
class PriorityQueueList :
	public PriorityQueueInterface <T>
{
private:
	//List<PriorityItem<T>> list;
public:
	PriorityQueueList(T firstData);
	PriorityQueueList();
	void Push() override;
	void Pop() override;
	void Empty() override;
	T top() override;	
};

