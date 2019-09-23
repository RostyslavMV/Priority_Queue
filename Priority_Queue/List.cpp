#include "List.h"

template<typename T>
Node<T>::Node(T data, int priority)
{
	this->data = data;
	this->priority = priority;
}

template<typename T>
void Node<T>::out()
{
	Node* current = this;
	while (current)
	{
		cout << current->data << ' ';
		current = current->next;
	}
	cout << endl;
}

template <template<class> class myNode, typename T>
List<myNode, T>::List(T firstData)
{
	begin = firstData;
}

template <template<class> class myNode, typename T>
void List<myNode, T>::out()
{
	begin->out();
}
