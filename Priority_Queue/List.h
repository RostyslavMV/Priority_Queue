#pragma once
#include<iostream>

using std::cout;
using std::endl;

template<typename T>
class Node 
{
public:
	T data;
	int priority; // Lower value means higher priority in queue
	Node* next;
	Node(T data, int priotity);
	void out(); // Output list from current node to the end
};

template<typename T>
class List
{
private:
	Node<T>* begin;
public:
	List(T firstData);
	void out();
};

