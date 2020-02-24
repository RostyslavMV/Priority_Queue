#pragma once
#include "PriorityQueueList.h"

template <typename T>
class PriorityQueueArrayList :
	public PriorityQueueList<T>
{
private:
	///
	/// List on wich priority queue is based
	///
	ArrayList<PriorityItem<T>> list;
public:
	///
	/// Constructor for priority queue with first element data
	///
	PriorityQueueArrayList(T firstData, double priority) :list(PriorityItem<T>(firstData, priority))
	{
	}
	///
	/// Default constructor for priority queue
	///
	PriorityQueueArrayList()
	{
	}
	///
	/// Create a new item with given data and priority and push it into priority queue.
	/// We iterate through the list untill new item's priority is higher and then insert it in a list. 
	///
	void Push(T data, double priority) override
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
	///
	/// Pop top element of priority queue (list[0] is a top one)
	/// 
	void Pop() override
	{
		if (Empty()) throw out_of_range("Atempt to pop from empty queue");
		list.Remove(list[0]);
	}
	///
	/// This bool returns true if priority queue is empty (inner list is empty)
	///
	bool Empty() override
	{
		if (list.Size() == 0) return true;
		return false;
	}
	///
	/// Returns top element in priority queue (list[0])
	///
	T Top() override
	{
		if (Empty()) throw out_of_range("Atempt to pop from empty queue");
		return list[0].value;
	}
	///
	/// Returns priority queue size, which is equal to inner list size
	///
	int Size() override {
		if (Empty()) throw out_of_range("Queue is empty");
		return list.Size();
	}
};

