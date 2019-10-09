#pragma once
#include "PriorityQueueList.h"

template <typename T>
class PriorityQueueArrayList :
	public PriorityQueueList<T>
{
private:
	ArrayList<PriorityItem<T>> list;
public:
	PriorityQueueArrayList(T firstData, int priority) :list(PriorityItem<T>(firstData, priority))
	{
	}
	PriorityQueueArrayList()
	{
		list.SetSize(0);
	}
	void Push(T data, int priority) override
	{
		PriorityItem<T> item(data, priority);
		if (list.Size() == 0) list.Add(item);
		else
		{
			if (list[0].priority > priority) list.InsertAtBegin(item);
			else
			{
				int currentId = 0;
				while (currentId + 1 < list.Size() && list[currentId + 1].priority <= priority) currentId++;
				list.Insert(list[currentId], item);
			}
		}
	}
	void Pop() override
	{
		list.Remove(list[0]);
	}
	bool Empty() override
	{
		if (list.Size() == 0) return true;
		return false;
	}
	T Top() override
	{
		return list[0].value;
	}
	int Size() override {
		return list.Size();
	}
};

