#include <iostream>
using namespace std;

struct BST_Node     //defenition of BST node.
{
    int Data;
    BST_Node* Left;
    BST_Node* Right;
};

BST_Node* GetNewNode(int Data)      //a function to create a new node.
{
    BST_Node* newNode= new BST_Node();
    newNode->Data = Data;
    newNode->Left = newNode->Right = NULL;
    return newNode;
}
BST_Node* Insert(BST_Node* Root, int Data)      //a function to insert elements.
{
    if(Root == NULL)    //an empty tree.
    {
        Root = GetNewNode(Data);    //if the tree is empty the 1st element will be the root.
        return Root;
    }
    else if(Data <= Root->Data) //if the element is less than the root, insert it in the left subtree.
    {
        Root->Left = Insert(Root->Left,Data);
    }
    else        //else insert it in the right subtree.
    {
        Root->Right = Insert(Root->Right,Data);
    }
    return Root;
}
bool Search(BST_Node* Root, int Data)       //a function to serach for an element.
{
    if(Root == NULL)    //an empty tree.
        return false;   //not found.
    else if (Root->Data == Data)    //found.
        return true;
    else if (Data <=Root->Data)
        return Search(Root->Left, Data);    //recursion.
    else
        return Search(Root->Right,Data);    //recursion.
}
int main(){
    BST_Node* Root = NULL;  //Creating an empty tree.

    Root = Insert(Root,14);     //inserting elements.
    Root = Insert(Root,29);
    Root = Insert(Root,7);
    Root = Insert(Root,12);
    Root = Insert(Root,42);
    //searching for an element.
    int Number;
    cout<<"Please, Enter The Number You Want To Find: ";
    cin>>Number;
    if(Search(Root,Number) == true)
        cout<<"Found\n";
	else
	    cout<<"Not Found\n";
}
