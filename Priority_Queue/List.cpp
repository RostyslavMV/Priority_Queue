#include "List.h"

template<typename T>
inline Node<T>::Node(T data, int priority)
{
	this->data = data;
	this->priority = priority;
}