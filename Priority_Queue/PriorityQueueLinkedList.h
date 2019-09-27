#pragma once
#include "PriorityQueueList.h"

template <typename T>
class PriorityQueueLinkedList :
	public PriorityQueueList<T>
{
private:
	DoublyLinkedList<PriorityItem<T>> list;
public:
	PriorityQueueLinkedList(T firstData, int priority) 
	{
		list = DoublyLinkedList<PriorityItem<T>>(firstData, priority);
	}
	PriorityQueueLinkedList()
	{
		list.SetSize(0);
	}
	void Push(T data, int priority) override 
	{
		//TODO
	}
	void Pop() override 
	{
		list.Remove(Top());
	}
	bool Empty() override {
		if (list.Size() == 0) return true;
		return false;
	}
	T Top() override {
		return list.begin.value;
	}
	int Size() override {
		return list.Size();
	}
};


