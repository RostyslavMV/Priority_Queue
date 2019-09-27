#pragma once
#include "PriorityQueueList.h"

template <typename T>
class PriorityQueueLinkedList :
	public PriorityQueueList<T>
{
private:
	DoublyLinkedList<PriorityItem<T>> list;
public:
	PriorityQueueLinkedList(T firstData, int priority);
	PriorityQueueLinkedList();
	void Push(T data, int priority) override;
	void Pop() override;
	bool Empty() override;
	T Top() override;
	int Size() override;
};


