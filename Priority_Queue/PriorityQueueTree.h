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
	PriorityQueueTree()
	{
	}
	PriorityQueueTree(T firstData, double priority)
	{
		PriorityTreeItem<T> item(firstData, priority);
		tree.²nsert(item);
	}
	void Push(T data, double priority) override
	{
		PriorityTreeItem<T> item(data, priority);
		tree.²nsert(item);		
	}
	void Pop() override
	{
		if (Empty()) throw out_of_range("Atempt to pop from empty queue");
		tree.DeleteKey(tree.MinNode()->data);
	}
	bool Empty() override
	{
		if (tree.Size() == 0) return true;
		return false;
	}
	int Size() override
	{
		return tree.Size();
	}
	T Top() override
	{
		if (Empty()) throw out_of_range("Queue is empty");
		return tree.MinNode()->data.value;
	}
};

