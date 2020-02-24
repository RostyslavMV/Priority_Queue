#pragma once
#include "PriorityQueueList.h"



template <typename T>
class PriorityQueueLinkedList :
	public PriorityQueueList<T>
{
private:
	DoublyLinkedList<PriorityItem<T>> list;
public:
	///
	/// Constructor to initialize priority queue with first element with given data and priority
	///
	PriorityQueueLinkedList(T firstData, double priority) : list(PriorityItem<T>(firstData, priority))
	{
	}
	///
	/// Default constructor
	///
	PriorityQueueLinkedList()
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
	///
	/// Output list starting from its begining
	///
	void outBeg() 
	{
		list.Begin()->Out();
	}
	///
	/// Pop top element of priority queue (list[0] is a top one)
	/// 
	void Pop() override 
	{
		if (Empty()) throw out_of_range("Atempt to pop from empty queue");
		list.RemoveNode(list.Begin());
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
	/// Returns top elemnet in priority queue 
	///
	T Top() override {
		if (Empty()) throw out_of_range("Queue is empty");
		return list.Begin()->data.value;
	}
	///
	/// Returns priority queue size, which is equal to inner list size
	///
	int Size() override {
		return list.Size();
	}

	~PriorityQueueLinkedList()
	{
	}
};


