#pragma once
#include <iostream>
#include <vector>
#include "PriorityQueueInterface.h"

using std::cout;
using std::endl;

template<typename T>
class ListNode {
public:
	T data;
	ListNode<T>* next;
	ListNode<T>* prev;
	ListNode(T data)
	{
		this->data = data;
		next = nullptr;
		prev = nullptr;
	}
	ListNode(T data, ListNode<T>* prev, ListNode<T>* next)
	{
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
	~ListNode()
	{
	}
	void Out()
	{
		ListNode* current = this;
		while (current)
		{
			//cout << current->data << ' ';
			current = current->next;
		}
		cout << endl;
	}
};

template<typename T>
class List {
protected:
	int size = 0;
public:
	virtual void Out() = 0;
	virtual void Add(T data) = 0;
	virtual bool Insert(T key, T data) = 0;
	virtual bool Remove(T key) = 0;
	virtual void InsertAtBegin(T data) = 0;
	int Size()
	{
		return size;
	}
};

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
class DoublyLinkedList : public List<T> {
private:
	ListNode<T>* begin = nullptr;
	ListNode<T>* end = nullptr;
public:
	ListNode<T>* Begin()
	{
		return begin;
	}
	ListNode<T>* End()
	{
		return end;
	}
	DoublyLinkedList(T firstData)
	{
		begin = new ListNode<T>(firstData);
		end = begin;
		this->size = 1;
	}
	DoublyLinkedList()
	{
		begin = nullptr;
		end = begin;
		this->size = 0;
	}
	~DoublyLinkedList()
	{
		ListNode<T>* current = begin, * toDelete;
		while (current)
		{
			toDelete = current;
			current = current->next;
			delete toDelete;
		}
		this->size = 0;
	}
	void Out() override
	{
		begin->Out();
	}
	void Add(T data) override
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
		this->size++;
	}

	void InsertAtBegin(T data) override
	{
		if (begin == nullptr)
		{
			this->Add(data);
		}
		else
		{
			ListNode<T>* node = new ListNode<T>(data, nullptr, begin);
			begin = node;
		}
		this->size++;
	}

	bool Insert(T key, T data) override
	{
		if (ListNode<T> * pkey = Find(begin, key))
		{
			ListNode<T>* node = new ListNode<T>(data, pkey, pkey->next);
			pkey->next = node;
			if (pkey != end)
				(node->next)->prev = node;
			else
				end = node;
			this->size++;
			return true;
		}
		return false;
	}

	bool Remove(T key) override
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
			this->size--;
			return true;
		}
		return false;
	}
	void RemoveNode(ListNode<T>* node)
	{
		if (node == begin)
		{
			begin = begin->next;
			if (begin != nullptr) begin->prev = nullptr;
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
		this->size--;
	}
};

template<typename T>
class ArrayList : public List<T> {
private:
	T* items;
	int capacity;
	const int INITIAL_CAPACITY = 4;
	void GrowCapacity()
	{
		capacity *= 2;
		T* new_items = new T[capacity];
		for (int i = 0; i < this->size; i++)
		{
			new_items[i] = items[i];
		}
		delete[] items;
		items = new_items;
	}
	int Find(T key)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (items[i] == key)
				return i;
		}
		return -1;
	}
public:
	T& operator[] (int index)
	{
		if (index >= this->size || index < 0)
		{
			throw std::out_of_range("Incorrect index");
		}
		return items[index];
	}
	ArrayList(T firstData)
	{
		items = new T[INITIAL_CAPACITY];
		items[0] = firstData;
		capacity = INITIAL_CAPACITY;
		this->size = 1;
	}
	ArrayList()
	{
		items = new T[INITIAL_CAPACITY];
		capacity = INITIAL_CAPACITY;
		this->size = 0;
	}
	~ArrayList() {
		delete[] items;
	}
	void Out() override
	{
		for (int i = 0; i < this->size; i++)
		{
			//cout << items[i] << " ";
		}
		cout << endl;
	}
	void Add(T data) override
	{
		if (this->size == capacity)
		{
			GrowCapacity();
		}
		items[this->size] = data;
		this->size++;
	}

	bool Insert(T key, T data) override
	{
		int keyIndex = Find(key);
		if (keyIndex == -1)
		{
			return false;
		}
		if (this->size == capacity)
		{
			GrowCapacity();
		}
		keyIndex++;
		for (int i = this->size; i > keyIndex; i--)
		{
			items[i] = items[i - 1];
		}
		items[keyIndex] = data;
		this->size++;
		return true;
	}

	void InsertAtBegin(T data) override
	{
		if (this->size == capacity)
		{
			GrowCapacity();
		}
		if (this->size == 0)
		{
			items[0] = data;
		}
		else
		{
			for (int i = this->size; i > 0; i--)
			{
				items[i] = items[i - 1];
			}
			items[0] = data;
		}
		this->size++;
	}

	bool Remove(T key) override
	{
		int keyIndex = Find(key);
		if (keyIndex == -1)
		{
			return false;
		}
		for (int i = keyIndex; i < this->size - 1; i++)
		{
			items[i] = items[i + 1];
		}
		this->size--;
		return true;
	}
};


