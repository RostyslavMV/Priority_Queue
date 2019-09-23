#pragma once

template <typename T>

class PriorityQueueInterface
{
private:
	int size;
public:
	virtual void Push() = 0;
	virtual void Pop() = 0;
	virtual void Empty() = 0;
	virtual T top() = 0;
	int Size() 
	{
		return size;
	}
};

