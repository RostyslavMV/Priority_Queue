#include "PriorityQueueLinkedList.h"

template<typename T>
PriorityQueueLinkedList<T>::PriorityQueueLinkedList(T firstData, int priority)
{
}

template<typename T>
PriorityQueueLinkedList<T>::PriorityQueueLinkedList()
{
	list.SetSize(0);
}

template<typename T>
void PriorityQueueLinkedList<T>::Push(T data, int priority)
{
	//TODO
}

template<typename T>
void PriorityQueueLinkedList<T>::Pop()
{
	list.Remove(Top());
}

template<typename T>
bool PriorityQueueLinkedList<T>::Empty()
{
	if (list.Size() == 0) return true;
	return false;
}

template<typename T>
T PriorityQueueLinkedList<T>::Top()
{
	return list.begin.value;
}

template<typename T>
int PriorityQueueLinkedList<T>::Size()
{
	return list.Size();
}
