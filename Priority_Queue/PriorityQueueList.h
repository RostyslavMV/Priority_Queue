#pragma once
#include "PriorityQueueInterface.h"
#include "List.h"


template <typename T>
class PriorityQueueList :
	public PriorityQueueInterface <T>
{
private:
	List<PriorityItem<T>>* list;
public:
	PriorityQueueList(T firstData, int firstPriority, bool useLinkedList);
	void Push(T data, int priority) override;
	void Pop() override;
	void Empty() override;
	T Top() override;
};
