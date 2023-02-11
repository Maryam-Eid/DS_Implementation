#include <iostream>
#include <cassert>
using namespace std;
template<class T>
class LinkedQueue
{
private:
	struct Node
	{
		T Item;
		Node* Next;
	};
	Node* HeadPtr;
	Node* TailPtr;
	int Length;

public:
	LinkedQueue() :HeadPtr(NULL), TailPtr(NULL), Length(0)
	{}

	bool IsEmpty()		//fuction to check if the queue in empty or not.
	{
		return Length == 0;
	}
	void DeQueue()		//function to remove item from the queue.
	{
		if (IsEmpty())
			cout << "Empty Queue" << endl;
		else if (Length == 1)
		{
			delete HeadPtr;
			TailPtr = NULL;
			Length = 0;
		}
		else
		{
			Node* Current = HeadPtr;
			HeadPtr = HeadPtr->Next;
			delete Current;		//free current.
			Length--;
		}
	}


	void EnQueue(T Item)		//function to add element in the queue.
	{
		Node* NewNode = new Node;
		NewNode->Item = Item;
		NewNode->Next = NULL;

		if (Length == 0)
			TailPtr = HeadPtr = NewNode;
		else
		{
			TailPtr->Next = NewNode;
			TailPtr = NewNode;
		}
		Length++;
	}
	T GetHead()		//function to find the first element in the queue.
	{
		assert(!IsEmpty());
		return HeadPtr->Item;
	}
	T GetTail()			 //function to find the last element in the queue.
	{
		assert(!IsEmpty());
		return TailPtr->Item;
	}
	void Display()		//function to print all the elements in the queue.
	{
		Node* Current = HeadPtr;
		cout << "Item In The Queue :[ ";
		while (Current != NULL)
		{
			cout << Current->Item << " ";
			Current = Current->Next;
		}cout << "]" << endl;
	}

	void ClearQueue()		//function to clear the queue.
	{
		Node* Current;

		while (HeadPtr != NULL)
		{
			Current = HeadPtr;
			HeadPtr = HeadPtr->Next;
			delete Current;
		}
		TailPtr = NULL;
		Length = 0;
	}

	int GetSize()		//function to get the size of the queue.
	{
		return Length;
	}
};

int main()
{
	LinkedQueue<int> Q1;

	Q1.EnQueue(106);
	Q1.EnQueue(58);
	Q1.EnQueue(98);
	Q1.Display();
}