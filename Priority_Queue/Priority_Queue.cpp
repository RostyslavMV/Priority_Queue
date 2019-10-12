#include <iostream>
#include "PriorityQueueLinkedList.h"
#include "PriorityQueueArrayList.h"
#include "PriorityQueueTree.h"

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
	 list->InsertAtBegin(-3);
	 cout << endl;
	 list->Out();
	 cout << endl;
	 cout << "Size = " << list->Size();
	 cout << endl;
	 list->Remove(88);
	 list->Out();
	 cout << endl;
	 cout << "Size = " << list->Size();
	 cout << endl;*/
	 /* List<int>* list2 = new ArrayList<int>();
	  for (int i = 0; i < 100; i++)
	  {
		  list2->Add(i);
	  }
	  list2->Out();
	  cout << endl;
	  cout << "Size = " << list2->Size();
	  list2->InsertAtBegin(-3);
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

	  //PriorityQueueLinkedList<int> pq(5, 2);
	  PriorityQueueArrayList<int> pq(5, 2);
	 // PriorityQueueTree<int> pq(5, 2);
	  pq.Push(3, 8);
	  pq.Push(2, 4);
	  pq.Push(7, 1);
	  
	  cout << pq.Top()<< " ";
	  pq.Pop();
	  cout << pq.Top() << " ";
	  pq.Pop();
	  cout << pq.Top() << " ";
	  pq.Pop();
	  cout << pq.Top() << " ";
	  pq.Pop();
	  pq.Push(8, 10);
	  cout << endl;
	  cout << "Size = " << pq.Size() << endl;
	  cout << "Empty = " << pq.Empty();
	
	  return 0;
}
