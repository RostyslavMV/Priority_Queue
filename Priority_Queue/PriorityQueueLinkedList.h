#pragma once
#include "PriorityQueueList.h"



template <typename T>
class PriorityQueueLinkedList :
	public PriorityQueueList<T>
{
private:
	DoublyLinkedList<PriorityItem<T>> list;
public:
	PriorityQueueLinkedList(T firstData, double priority) : list(PriorityItem<T>(firstData, priority))
	{
	}

	PriorityQueueLinkedList()
	{
	}

	void Push(T data, double priority) override 
	{
		PriorityItem<T> item(data, priority);
		if (list.Size() == 0) list.Add(item);
		else
		{
			if (priority < list.Begin()->data.priority) list.InsertAtBegin(item);
			else
			{
				ListNode<PriorityItem<T>>* currentNode = list.Begin();
				while (currentNode->next != nullptr && currentNode->next->data.priority <= priority)
				{
					currentNode = currentNode->next;
				}
				list.Insert(currentNode->data, item);
			}
		}
	}

	void outBeg() 
	{
		list.Begin()->Out();
	}

	void Pop() override 
	{
		if (Empty()) throw out_of_range("Atempt to pop from empty queue");
		list.RemoveNode(list.Begin());
	}

	bool Empty() override 
	{
		if (list.Size() == 0) return true;
		return false;
	}

	T Top() override {
		if (Empty()) throw out_of_range("Queue is empty");
		return list.Begin()->data.value;
	}

	int Size() override {
		return list.Size();
	}

	~PriorityQueueLinkedList()
	{
	}
};


