#pragma once
#include "PriorityQueueInterface.h"
#include "AVLtree.h"

using std::out_of_range;

template <typename T>
class PriorityQueueTree :
	public PriorityQueueInterface <T>
{
private:
	AVLtree<PriorityTreeItem<T>> tree;
public:
	///
	/// Default constructor
	///
	PriorityQueueTree()
	{
	}
	///
	/// Constructor for priority queue with first element data
	///
	PriorityQueueTree(T firstData, double priority)
	{
		PriorityTreeItem<T> item(firstData, priority);
		tree.²nsert(item);
	}
	///
	/// Create a new item with given data and priority and push it into priority queue.
	/// We just use insert function for an AVLTree, because it is an ordered tree
	///
	void Push(T data, double priority) override
	{
		PriorityTreeItem<T> item(data, priority);
		tree.²nsert(item);		
	}
	///
	/// Pop top element of priority queue (list[0] is a top one)
	/// 
	void Pop() override
	{
		if (Empty()) throw out_of_range("Atempt to pop from empty queue");
		tree.DeleteKey(tree.MinNode()->data);
	}
	///
	/// This bool returns true if priority queue is empty (inner list is empty)
	///
	bool Empty() override
	{
		if (tree.Size() == 0) return true;
		return false;
	}
	///
	/// Returns priority queue size, which is equal to inner list size
	///
	int Size() override
	{
		return tree.Size();
	}
	///
	/// Returns top elemnet in priority queue 
	///
	T Top() override
	{
		if (Empty()) throw out_of_range("Queue is empty");
		return tree.MinNode()->data.value;
	}
};

