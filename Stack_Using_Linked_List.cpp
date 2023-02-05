#include <iostream>
using namespace std;
template<class T>   //to allow the array to recieve any data type. 
class Stack {
	struct Node
	{
		T Item;
		Node* Next;
	};
	Node* Top, * Cur;
public:
	Stack() {
		Top = NULL;
	}
	bool IsEmpty() //To check if the stack is empty or not.
	{
		return Top == NULL;
	}
	void Push(T NewItem)  //to add a new element in the stack.
	{
		Node* NewItemPtr = new Node;
		if (NewItemPtr == NULL)
			cout << "Stack Push Can't Allocate Memory.";
		else
		{
			NewItemPtr->Item = NewItem;
			NewItemPtr->Next = Top;
			Top = NewItemPtr;
		}

	}

	void Pop()   //to remove the top element of the stack without sotoring.
	{
		if (IsEmpty())
			cout << "Stack Empty On Pop.";
		else
		{
			Node* Temp = Top;
			Top = Top->Next;
			Temp = Temp->Next = NULL;
			delete Temp;
		}
	}
	void Pop(T& StackTop)   //to remove the top element of the stack and store it.		// '&' to call by reference.
	{
		if (IsEmpty)
			cout << "Stack Empty On Pop.";
		else
		{
			StackTop = Top->Item;
			Node* Temp = Top;
			Top = Top->Next;
			Temp = Temp->Next = NULL;
			delete Temp;
		}
	}
	void GetTop(T& StackTop)		//to print the top element.
	{
		if (IsEmpty())
			cout << "Stack Empty On GetTop.";
		else
		{
			StackTop = Top->Item;
			cout << "\nTop Element Of The Stack is " << StackTop;
			cout << endl;
		}
		
	} 
	void Display()		//to print all the elements in the stack.
	{
		Cur = Top;
		cout << "\nItmes In The Stack : ";
		cout << "[";
		while (Cur != NULL)
		{
			cout << Cur->Item << " ";
			Cur = Cur->Next;
		}
		cout << "]\n";

	}

};
int main()
{
	Stack<int>S;
	S.Push(100);
	S.Push(200);
	S.Push(300);
	S.Pop();
	S.Display();
	int y = 0;
	S.GetTop(y);
	cout << y << endl;
}
