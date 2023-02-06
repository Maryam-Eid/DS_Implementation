#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool ArePair(char Open, char Close)  //to check if the left and the right parentheses matches.
{
	if (Open == '(' && Close == ')')
		return true;
	else if (Open == '{' && Close == '}')
		return true;
	else if (Open == '[' && Close == ']')
		return true;
	return false;    
}
bool AreBalanced(string Exp)      
{
	stack<char>S;
	for (int i = 0;i < Exp.length();i++)			 //to check all the stack elements.
	{
		if (Exp[i] == '(' || Exp[i] == '{' || Exp[i] == '[')			//if there is a left parenthesis push it into the stack.
			S.push(Exp[i]);
		else if (Exp[i] == ')' || Exp[i] == '}' || Exp[i] == ']')
		{		
			if (S.empty() || !ArePair(S.top(), Exp[i]))			//if the right parenthesis doesn't match the top of the stack, or if the stack is empty.
				return false;
			else
				S.pop();
		}


	}
	return S.empty()? true:false;    //if the stack is empty then the expression is balanced otherwise it's not.
}

int main()
{
	string Expression;
	cout << "Please, Enter An Expression";
	cin >> Expression;
	if (AreBalanced(Expression))
		cout << "Balanced\n";
	else
		cout << "Not Balanced";
}
