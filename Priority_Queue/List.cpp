#include "List.h"

template<typename T>
ListNode<T>* Find(ListNode<T>* const beg, T d)
{
	ListNode<T>* current = beg;
	while (current)
	{
		if (current->data == d)
			break;
		current = current->next;
	}
	return current;
}

template<typename T>
ListNode<T>::ListNode(T data)
{
	this->data = data;
	next = nullptr;
	prev = nullptr;
}

template<typename T>
ListNode<T>::ListNode(T data, ListNode<T>* prev, ListNode<T>* next)
{
	this->data = data;
	this->next = next;
	this->prev = prev;
}
template<typename T>
ListNode<T>::~ListNode()
{
}

template<typename T>
void ListNode<T>::Out()
{
	ListNode* current = this;
	while (current)
	{
		cout << current->data << ' ';
		current = current->next;
	}
	cout << endl;
}


template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(T firstData)
{
	begin = new ListNode<T>(firstData);
	end = begin;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	begin = nullptr;
	end = begin;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	ListNode<T>* current = begin, * toDelete;
	while (current)
	{
		toDelete = current;
		current = current->next;
		delete toDelete;
	}
}

template<typename T>
void DoublyLinkedList<T>::Out()
{
	begin->Out();
}

template<typename T>
void DoublyLinkedList<T>::Add(T data)
{
	ListNode<T>* node = new ListNode<T>(data);
	if (begin == nullptr)
	{
		begin = node;
		end = node;
	}
	else
	{
		end->next = node;
		node->prev = end;
		node->next = nullptr;
		end = node;
	}
}

template<typename T>
bool DoublyLinkedList<T>::Insert(T key, T data)
{
	if (ListNode<T> * pkey = Find(begin, key))
	{
		ListNode<T>* node = new ListNode<T>(data, pkey, pkey->next);
		pkey->next = node;
		if (pkey != end)
			(node->next)->prev = node;
		else
			end = node;
		return true;
	}
	return false;
}

template<typename T>
bool DoublyLinkedList<T>::Remove(T key)
{
	if (ListNode<T> * node = Find(begin, key))
	{
		if (node == begin)
		{
			begin = begin->next;
			begin->prev = nullptr;
		}
		else if (node == end)
		{
			end = end->prev;
			end->next = nullptr;
		}
		else
		{
			(node->prev)->next = node->next;
			(node->next)->prev = node->prev;
		}
		delete node;
		return true;
	}
	return false;
}

template<typename T>
void ArrayList<T>::GrowCapacity()
{
	capacity *= 2;
	T* new_items = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		new_items[i] = items[i];
	}
	delete[] items;
	items = new_items;
}

template<typename T>
ArrayList<T>::ArrayList(T firstData)
{
	items = new T[INITIAL_CAPACITY];
	items[0] = firstData;
	capacity = INITIAL_CAPACITY;
	size = 1;
}

template<typename T>
ArrayList<T>::ArrayList()
{
	items = new T[INITIAL_CAPACITY];
	capacity = INITIAL_CAPACITY;
	size = 0;
}

template<typename T>
int ArrayList<T>::Find(T key)
{
	for (int i = 0; i < size; i++)
	{
		if (items[i] == key)
			return i;
	}
	return -1;
}

template<typename T>
ArrayList<T>::~ArrayList()
{
	delete[] items;
}

template<typename T>
void ArrayList<T>::Out()
{
	for (int i = 0; i < size; i++)
	{
		cout << items[i] << " ";
	}
	cout << endl;
}

template<typename T>
void ArrayList<T>::Add(T data)
{
	if (size == capacity)
	{
		GrowCapacity();
	}
	items[size] = data;
	size++;
}

template<typename T>
bool ArrayList<T>::Insert(T key, T data)
{
	int keyIndex = Find(key);
	if (keyIndex == -1)
	{
		return false;
	}
	if (size == capacity)
	{
		GrowCapacity();
	}
	keyIndex++;
	for (int i = size; i > keyIndex; i--)
	{
		items[i] = items[i - 1];
	}
	items[keyIndex] = data;
	size++;
	return true;
}

template<typename T>
bool ArrayList<T>::Remove(T key)
{
	int keyIndex = Find(key);
	if (keyIndex == -1)
	{
		return false;
	}
	for (int i = keyIndex; i < size - 1; i++)
	{
		items[i] = items[i + 1];
	}
	return true;
}

void temp(){
	DoublyLinkedList<int> list;
}