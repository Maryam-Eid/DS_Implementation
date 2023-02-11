#include <iostream>
#include <vector>
using namespace std;


void Swap(int *A, int *B)       // a function to swap position of 2 elements.
 {
  int Temp = *B;
  *B = *A;
  *A = Temp;
}

void Heapify(vector<int> &hT, int i)        // a fnction to heapify the tree.
 {
  int Size = hT.size();

  int Largest = i;
  int Left = 2 * i + 1;    //left child.
  int Right = 2 * i + 2;    //right child
// Find the largest among root.
  if (Left < Size && hT[Left] > hT[Largest])
    Largest = Left;
  if (Right < Size && hT[Right] > hT[Largest])
    Largest = Right;


  if (Largest != i)      // Swap and continue heapifying if root is not largest.
  {
    Swap(&hT[i], &hT[Largest]);
    Heapify(hT, Largest);
  }
}

void Insert(vector<int> &hT, int NewNum)        //a function to insert an element.
{
  int Size = hT.size();
  if (Size == 0) {
    hT.push_back(NewNum);
  } else {
    hT.push_back(NewNum);
    for (int i = Size / 2 - 1; i >= 0; i--) {
      Heapify(hT, i);
    }
  }
}

void DeleteNode(vector<int> &hT, int Num)       //a function to delete an element.

 {
  int Size = hT.size();
  int i;
  for (i = 0; i < Size; i++) {
    if (Num == hT[i])
      break;
  }
  Swap(&hT[i], &hT[Size - 1]);

  hT.pop_back();
  for (int i = Size / 2 - 1; i >= 0; i--) {
    Heapify(hT, i);
  }
}

void PrintArray(vector<int> &hT)        // Print the elements of the tree.
 {
  for (int i = 0; i < hT.size(); ++i)
    cout << hT[i] << " ";
  cout << "\n";
}

int main()
{
  vector<int> HeapTree;

  Insert(HeapTree, 7);
  Insert(HeapTree, 8);
  Insert(HeapTree, 4);
  Insert(HeapTree, 6);
  Insert(HeapTree, 2);
  Insert(HeapTree, 1);

  cout << "Max Heap Array: ";
  PrintArray(HeapTree);

  DeleteNode(HeapTree, 6);

  cout << "After Deleting An Element: ";

  PrintArray(HeapTree);
}