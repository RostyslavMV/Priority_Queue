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
			cout << current->data << ' ';
			current = current->next;
		}
		cout << endl;
	}
};

template<typename T>
class List {
private:
	int size;
public:
	virtual void Out() = 0;
	virtual void Add(T data) = 0;
	virtual bool Insert(T key, T data) = 0;
	virtual bool Remove(T key) = 0;
	int Size()
	{
		return size;
	}
	void SetSize(int newSize) {
		size = newSize;
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
	ListNode<T>* begin;
	ListNode<T>* end;

public:
	DoublyLinkedList(T firstData)
	{
		begin = new ListNode<T>(firstData);
		end = begin;
	}
	DoublyLinkedList()
	{
		begin = nullptr;
		end = begin;
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
	}
	bool  Insert(T key, T data) override
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
			return true;
		}
		return false;
	}
};

template<typename T>
class ArrayList : public List<T> {
private:
	int capacity;
	const int INITIAL_CAPACITY = 4;
	void GrowCapacity()
	{
		capacity *= 2;
		int size = this->Size();
		T* new_items = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			new_items[i] = items[i];
		}
		delete[] items;
		items = new_items;
	}
	int Find(T key)
	{
		int size = this->Size();
		for (int i = 0; i < size; i++)
		{
			if (items[i] == key)
				return i;
		}
		return -1;
	}
public:
	T* items;
	ArrayList(T firstData)
	{
		items = new T[INITIAL_CAPACITY];
		items[0] = firstData;
		capacity = INITIAL_CAPACITY;
		this->SetSize(1);
	}
	ArrayList()
	{
		items = new T[INITIAL_CAPACITY];
		capacity = INITIAL_CAPACITY;
		this->SetSize(0);
	}
	~ArrayList() {
		delete[] items;
	}
	void Out() override
	{
		int size = this->Size();
		for (int i = 0; i < size; i++)
		{
			cout << items[i] << " ";
		}
		cout << endl;
	}
	void Add(T data) override
	{
		int size = this->Size();
		if (size == capacity)
		{
			GrowCapacity();
		}
		items[size] = data;
		size++;
	}
	bool Insert(T key, T data) override
	{
		int keyIndex = Find(key);
		if (keyIndex == -1)
		{
			return false;
		}
		int size = this->Size();
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
	bool Remove(T key) override
	{
		int keyIndex = Find(key);
		if (keyIndex == -1)
		{
			return false;
		}
		int size = this->Size();
		for (int i = keyIndex; i < size - 1; i++)
		{
			items[i] = items[i + 1];
		}
		return true;
	}
};


