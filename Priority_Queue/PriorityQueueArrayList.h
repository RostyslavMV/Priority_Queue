#pragma once
#include "PriorityQueueList.h"

template <typename T>
class PriorityQueueArrayList :
	public PriorityQueueList<T>
{
private:
	ArrayList<PriorityItem<T>> list;
public:
	PriorityQueueArrayList(T firstData, int priority);
	PriorityQueueArrayList();
	void Push(T data, int priority) override;
	void Pop() override;
	bool Empty() override;
	T Top() override;
	int Size() override;
};


