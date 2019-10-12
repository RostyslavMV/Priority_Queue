#pragma once
#include "PriorityQueueInterface.h"
#include "AVLtree.h"

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
	PriorityQueueTree(T firstData, int priority)
	{
		PriorityTreeItem<T> item(firstData, priority);
		tree.²nsert(item);
	}
	void Push(T data, int priority) override
	{
		PriorityTreeItem<T> item(data, priority);
		tree.²nsert(item);		
	}
	void Pop() override
	{
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
		return tree.MinNode()->data.value;
	}
};

