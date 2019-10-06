#include <iostream>
#include "PriorityQueueLinkedList.h"

int main()
{
	/* List<int>* list = new DoublyLinkedList<int>();
	 for (int i = 0; i < 100; i++)
	 {
		 list->Add(i);
	 }
	 list->Out();
	 cout << endl;
	 cout << "Size = " << list->Size();
	 list->Insert(5, 6);
	 cout << endl;
	 list->Out();
	 cout << endl;
	 cout << "Size = " << list->Size();
	 cout << endl;
	 list->Remove(88);
	 list->Out();
	 cout << endl;
	 cout << "Size = " << list->Size();
	 cout << endl;
	 List<int>* list2 = new ArrayList<int>();
	 for (int i = 0; i < 100; i++)
	 {
		 list2->Add(i);
	 }
	 list2->Out();
	 cout << endl;
	 cout << "Size = " << list2->Size();
	 list2->Insert(5, 6);
	 cout << endl;
	 list2->Out();
	 cout << endl;
	 cout << "Size = " << list2->Size();
	 cout << endl;
	 list2->Remove(88);
	 list2->Out();
	 cout << endl;
	 cout << "Size = " << list2->Size();
	 cout << endl; */
	int val = 5;
	PriorityQueueLinkedList<int> pq(val, 1 / val);
	
}
