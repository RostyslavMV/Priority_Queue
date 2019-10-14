#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include"List.h"
#include "PriorityQueueInterface.h"
#include "PriorityQueueTree.h"
#include "PriorityQueueArrayList.h"
#include "PriorityQueueLinkedList.h"
#include "Shape.h"

double Parabola(double x)
{
	return x * x;
}

double Sqrt(double x)
{
	return sqrt(x);
}

double Abs(double x)
{
	return abs(x);
}

double Log(double x)
{
	return log(x);
}

TEST_CASE("Lists test", "[lists]") {
	List<int>* list1 = new DoublyLinkedList<int>();
	List<int>* list2 = new ArrayList<int>();
	for (int i = 0; i < 100; i++)
	{
		list1->Add(i);
		list2->Add(i);
	}
	REQUIRE(list1->Size() == 100);
	REQUIRE(list2->Size() == 100);
	for (int i = 0; i < 10; i++)
	{
		list1->Remove(i);
		list2->Remove(i);
	}
	REQUIRE(list1->Size() == 90);
	REQUIRE(list2->Size() == 90);
}

TEST_CASE("Priority Queue test", "[priority queue]")
{
	PriorityQueueInterface<double>* priorityQueueTree = new PriorityQueueTree<double>();
	PriorityQueueInterface<double>* priorityQueueArrayList = new PriorityQueueArrayList<double>();
	PriorityQueueInterface<double>* priorityQueueLinkedList = new PriorityQueueLinkedList<double>();
	for (int i = 1; i <= 10; i++)
	{
		double value = 1.0 / i;
		priorityQueueTree->Push(value, i);
		priorityQueueArrayList->Push(value, i);
		priorityQueueLinkedList->Push(value, i);
	}
	REQUIRE_FALSE(priorityQueueTree->Empty());
	REQUIRE_FALSE(priorityQueueArrayList->Empty());
	REQUIRE_FALSE(priorityQueueLinkedList->Empty());
	REQUIRE(priorityQueueTree->Size() == 10);
	REQUIRE(priorityQueueArrayList->Size() == 10);
	REQUIRE(priorityQueueLinkedList->Size() == 10);
	REQUIRE(priorityQueueTree->Top() == 1);
	REQUIRE(priorityQueueArrayList->Top() == 1);
	REQUIRE(priorityQueueLinkedList->Top() == 1);
	priorityQueueTree->Pop();
	priorityQueueArrayList->Pop();
	priorityQueueLinkedList->Pop();
	REQUIRE(priorityQueueTree->Size() == 9);
	REQUIRE(priorityQueueArrayList->Size() == 9);
	REQUIRE(priorityQueueLinkedList->Size() == 9);
	REQUIRE(priorityQueueTree->Top() == 0.5);
	REQUIRE(priorityQueueArrayList->Top() == 0.5);
	REQUIRE(priorityQueueLinkedList->Top() == 0.5);
	int size = 9;
	for (int i = 20; i >= 1; i--)
	{
		double value = 1.0 / i;
		priorityQueueTree->Push(value, i);
		priorityQueueArrayList->Push(value, i);
		priorityQueueLinkedList->Push(value, i);
		size++;
		REQUIRE(priorityQueueTree->Size() == size);
		REQUIRE(priorityQueueArrayList->Size() == size);
		REQUIRE(priorityQueueLinkedList->Size() == size);
	}
	for (int i = 0; i < size; i++)
	{
		REQUIRE(priorityQueueTree->Top() == priorityQueueArrayList->Top());
		REQUIRE(priorityQueueArrayList->Top() == priorityQueueLinkedList->Top());
		priorityQueueTree->Pop();
		priorityQueueArrayList->Pop();
		priorityQueueLinkedList->Pop();
	}
	REQUIRE(priorityQueueTree->Empty());
	REQUIRE(priorityQueueArrayList->Empty());
	REQUIRE(priorityQueueLinkedList->Empty());
}

TEST_CASE("Shapes test", "[shapes]")
{
	Shape* shape1 = new ShapeX(-6, 3, Parabola);
	//81 is analytical integral answer
	REQUIRE(abs(shape1->Area() - 81) < 0.0001);
	// 46.667~ is perymeter finding arc length by integrating https://en.wikipedia.org/wiki/Arc_length
	// plus other sides (36,9,9)
	REQUIRE(abs(shape1->Perimeter() - 100.667) < 100.667*0.00001);
	Shape* shape2 = new Shape2Functions(0.1, 5, Sqrt, Log);
	REQUIRE(abs(shape2->Area() - 4.05503) < 0.0001);
	// Function does not not provide inaccurate answer here, 15.47 is not a very accurate
	//analytycal answer, because of rounding
	REQUIRE(abs(shape2->Perimeter() - 15.47) < 15.47*0.0005);
	Shape* shapeA = new ShapeX(0, 2, Parabola);
	Shape* shapeB = new Shape2Functions(1, 5, Sqrt, Log);
	Shape* shape3 = new ShapeIntersection(shapeA, shapeB);
	REQUIRE(abs(shape3->Area()-0.83266) < 0.0001);
	REQUIRE(abs(shape3->Perimeter() - 4.02617) < 4.02617 * 0.0001);
	PriorityQueueInterface<Shape*>* priorityQueueTree = new PriorityQueueTree<Shape*>();
	PriorityQueueInterface<Shape*>* priorityQueueArrayList = new PriorityQueueArrayList<Shape*>();
	PriorityQueueInterface<Shape*>* priorityQueueLinkedList = new PriorityQueueLinkedList<Shape*>();
	priorityQueueTree->Push(shape1,shape1->Area());
	priorityQueueTree->Push(shape3, shape3->Area());
	priorityQueueTree->Push(shape2, shape2->Area());
	priorityQueueArrayList->Push(shape3, shape3->Area());
	priorityQueueArrayList->Push(shape1, shape1->Area());
	priorityQueueArrayList->Push(shape2, shape2->Area());
	priorityQueueLinkedList->Push(shape1, shape1->Area());
	priorityQueueLinkedList->Push(shape2, shape2->Area());
	priorityQueueLinkedList->Push(shape3, shape3->Area());
	for (int i = 0; i < priorityQueueTree->Size(); i++)
	{
		REQUIRE(priorityQueueTree->Top() == priorityQueueArrayList->Top());
		REQUIRE(priorityQueueArrayList->Top() == priorityQueueLinkedList->Top());
		priorityQueueTree->Pop();
		priorityQueueArrayList->Pop();
		priorityQueueLinkedList->Pop();
	}
}