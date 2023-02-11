#include <iostream>
using namespace std;
const int Max_Size = 150;
template <class T>  //to allow the stack to receive any data type.
class Stack {
	int Top;		//represent the index of the stack.
	int Item[Max_Size];
public:
	Stack()
	{
		Top = -1;
	}
	void Push(T Element)  //to add elements into the stack.
	{
		if (Top >= Max_Size - 1)   //to check if the sstack is full, (Max_Size-1) beacuse the stack index start at 0.
		{
			cout << "Stack Full On Push.";
		}
		else
		{
			Top++;			//Top=0.
			Item[Top] = Element;
		}
	}
	bool IsEmpty()   //to check if the stack is empty or not.
	{
		return Top < 0;
	}
	void Pop()   //just remove the element without storing it.
	{
		if (IsEmpty())
			cout << "Stack Empty On Pop";
		else
			Top--;
	}

	void Pop(T&Element) //remove the element and store it.  // '&' to call by reference.
	{
		if (IsEmpty())
			cout << "Stack Empty On Pop.";
		else {
			Element = Item[Top];
			Top--;
		}

	}

	void GetTop(T& StackTop)  //to get the top element in the stack.
	{
		if (IsEmpty())
			cout << "Stack Empty On Pop.";
		else {
			StackTop = Item[Top];
			cout << StackTop << endl;
		}
	}

	void Print()		//to print all the stack element.
	{
		cout << "[";
		for (int i = Top; i >= 0; i--)
		{
			cout << Item[i] << " ";
		}
		cout << "]";
		cout << endl;
	}
};

int main()
{
	Stack<int>S;
	S.Push(5);
	S.Push(10);
	S.Push(15);
	S.Push(20);
	S.Pop();
	S.Push(7);
	S.Print();
}