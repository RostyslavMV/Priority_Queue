#include "PriorityQueueArrayList.h"

template<typename T>
PriorityQueueArrayList<T>::PriorityQueueArrayList(T firstData, int priority)
{
	PriorityItem<T> first(firstData, priority);
	this->list(first);
}

template<typename T>
PriorityQueueArrayList<T>::PriorityQueueArrayList()
{
	list.SetSize(0);
}

template<typename T>
void PriorityQueueArrayList<T>::Push(T data, int priority)
{
	//TODO 	
}

template<typename T>
void PriorityQueueArrayList<T>::Pop()
{
	list.Remove(Top());
}

template<typename T>
bool PriorityQueueArrayList<T>::Empty()
{
	if (list.Size() == 0) return true;
	return false;
}


template<typename T>
T PriorityQueueArrayList<T>::Top()
{
	return list.items[0].value;
}

template<typename T>
int PriorityQueueArrayList<T>::Size()
{
	return list.Size();
}

template class PriorityQueueArrayList<int>;
template class PriorityQueueArrayList<double>;
template class PriorityQueueArrayList<string>;
template class PriorityQueueArrayList<vector<int>>;


