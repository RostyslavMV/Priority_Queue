#pragma once
#include "PriorityQueueList.h"

template <typename T>
class PriorityQueueArrayList :
	public PriorityQueueList<T>
{
private:
	ArrayList<PriorityItem<T>> list;
public:
	PriorityQueueArrayList(T firstData, int priority) 
	{
		PriorityItem<T> first(firstData, priority);
		list = ArrayList<PriorityItem<T>>(first);
	}
	PriorityQueueArrayList()
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
	bool Empty() override
	{
		if (list.Size() == 0) return true;
		return false;
	}
	T Top() override
	{
		return list.items[0].value;
	}
	int Size() override {
		return list.Size();
	}
};

