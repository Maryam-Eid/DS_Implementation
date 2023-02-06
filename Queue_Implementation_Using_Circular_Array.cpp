#include <iostream>
#include <cassert>
using namespace std;
const int Max_Length = 150;			//to define the array size.
class ArrayQueueType
{
	int Tail;		//lasr element.
	int Head;		//first element.
	int Length;
	int Arr[Max_Length];
public:
	ArrayQueueType() {
		Head = 0;
		Tail = Max_Length - 1;
		Length = 0;
	}
	bool IsEmpty()		//to check if the queeue is empty or not.
	{
		return Length == 0;		//no elements inside the queue.
	}
	bool IsFull()		//to check if the queeue is full or not.
	{
		return Length == Max_Length;
	}
	void Insert(int Element)		//to add an element in the queue.
	{
		if (IsFull())		//first we nead to check that the queeu is not full.
			cout << "Queue Is Full, Can't Enqueue!";
		else
		{
			Tail = (Tail + 1) % Max_Length;
			Arr[Tail] = Element;
			Length++;
		}
	}
	void Delete()		//to delete an element in the queue.
	{
		if (IsEmpty())			//first we nead to check that the queeu is not empty.
			cout << "Queue Is Empty, Can't Dequeue!";
		else
		{
			Head = (Head + 1) % Max_Length;
			Length--;
		}

	}
	int GetHead()		//to get the first element.
	{
		assert(!IsEmpty());
		return Arr[Head];			//if the queue not empty return the head value.
	}
	int GetTail()			//to get the lastt element.
	{
		assert(!IsEmpty());
		return Arr[Tail];		//if the queue not empty return the tail value.
	}
	void Print()		//to print all elements in the queue.
	{
		if (!IsEmpty())
		{
			for (int i = Head; i != Tail;i = (i + 1) % Max_Length)
				cout << Arr[i] << " ";
			cout << Arr[Tail];
		}
		else
			cout << "Empty Queeu";
	}
	int Search(int Item)		//to find an element in the queue.
	{
		int Pos = -1;
		if (!IsEmpty())
		{
			for (int i = Head; i != Tail; i = (i + 1) % Max_Length)

				if (Arr[i] == Item)			//if the element is found. 
				{
					Pos = i;
					break;
				}

			if (Pos == -1)		//if the element not found.
			{
				if (Arr[Tail] == Item)		//check if the element we want is the Tail.
					Pos = Tail;
			}
		}
		else
		{
			cout << "Queue Is Empty." << endl;
		}
		return Pos;
	}
};
int main()
{
	ArrayQueueType Q1;
	Q1.Insert(10);
	Q1.Insert(20);
	Q1.Insert(30);
	Q1.Insert(40);
	Q1.Print();
	cout << "\n";
	cout << Q1.Search(30) << endl;

}
