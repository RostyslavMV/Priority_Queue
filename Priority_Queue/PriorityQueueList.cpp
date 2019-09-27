#include "PriorityQueueList.h"

template<typename T>
PriorityQueueList<T>::PriorityQueueList(T firstData, int firstPriority, bool useLinkedList)
{
	PriorityItem<T> first(firstData, firstPriority);
	if (useLinkedList)
	{
		list = new DoublyLinkedList<PriorityItem<T>>(first);
	}
	else
	{
		list = new ArrayList<PriorityItem<T>>(first);
	}
}

template<typename T>
void PriorityQueueList<T>::Push(T data, int priority)
{
	PriorityItem<T> item(data, priority);
	if (Empty())
	{
		list->Add(item);
	}
	else
	{
		if (list = dynamic_cast<List<PriorityItem<T>>*>(DoublyLinkedList<PriorityItem<T>>))
		{

		}
		else
		{

		}
	}
}

template<typename T>
void PriorityQueueList<T>::Pop()
{
	list->Remove(Top());
}

template<typename T>
void PriorityQueueList<T>::Empty()
{
	if (list = dynamic_cast<List<PriorityItem<T>>*>(DoublyLinkedList<PriorityItem<T>>))
	{
		if (list->begin == nullptr) return true;
		return false;
	}
	else
	{
		if (list->size == 0) return true;
		return false;
	}
}

template<typename T>
T PriorityQueueList<T>::Top()
{
	if (list = dynamic_cast<List<PriorityItem<T>>*>(DoublyLinkedList<PriorityItem<T>>))
	{
		return list->begin->value;
	}
	else
	{
		return list->items[0];
	}
}

void TemporaryFunction()
{
	//PriorityQueueList<int> TempObj;
}