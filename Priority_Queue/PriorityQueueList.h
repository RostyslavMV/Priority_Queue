#pragma once
#include "PriorityQueueInterface.h"
#include "List.h"

template <typename myNode, typename T>
class PriorityQueueList :
	public PriorityQueueInterface <T>
{
private:
	List<T> mList;
public:
	PriorityQueueList(T firstData);
	void Push() override;
	void Pop() override;
	void Empty() override;
	T top() override;	
};


