#pragma once
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

template<typename T>
class ListNode {
public:
	T data;
	ListNode<T>* next;
	ListNode<T>* prev;
	ListNode(T data);
	ListNode(T data, ListNode<T>* prev, ListNode<T>* next);
	~ListNode();
	void Out();
};

template<typename T>
class List {
public:
	virtual void Out() = 0;
	virtual void Add(T data) = 0;
	virtual bool Insert(T key, T data) = 0;
	virtual bool Remove(T key) = 0;
}; 

template<typename T>
ListNode<T>* Find(ListNode<T>* const beg, T d);

template<typename T>
class DoublyLinkedList : public List<T> {
private:
	ListNode<T>* begin;
	ListNode<T>* end;
public:
	DoublyLinkedList(T first_data);
	~DoublyLinkedList();
	void Out() override;
	void Add(T data) override;
	bool  Insert(T key, T data) override;
	bool Remove(T key) override;
};

template<typename T>
class ArrayList : public List<T> {
private:
	int size;
	int capacity;
	T* items;
	const int INITIAL_CAPACITY = 4;
	void GrowCapacity();
	int Find(T key);
public:
	ArrayList(T firstData);
	~ArrayList();
	void Out() override;
	void Add(T data) override;
	bool Insert(T key, T data) override;
	bool Remove(T key) override;
};