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

template<typename T>
List<T>::List(T firstData)
{
	begin = new Node<T>(firstData);
}

template<typename T>
void List<T>::out()
{
	begin->out();
}
