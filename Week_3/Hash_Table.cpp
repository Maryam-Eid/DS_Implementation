#include <iostream>
#include <list>
#include <cstring>
using namespace std;

//for example we will implement a phonebook (phone num, name)
class HashTable
{
    private:
        static const int HashGroups =10;  //10 lists.
        list<pair<int, string>> table[HashGroups];  //list 1, indix 0, list 2, index 1...
    public:
        bool IsEmpty() const;
        int HashFunction(int Key);
        void Insert(int Key, string Value);
        void Remove(int Key);
        string Search(int Key);
        void Print();
};

 bool HashTable::IsEmpty() const    //a function to check if the HT is empty or not.
{
    int Sum{};
    for (int i{}; i < HashGroups; i++)  //check the size of every list.
        Sum += table[i].size();     

    if (!Sum)       //if sum = 0.
        return true;    //it's empty.
    return
        false;  //if sum !=0 .
}

int HashTable::HashFunction(int Key)
{
    //to return a value between 0 & 9 because we only have 10 lists.
    return Key % HashGroups;    //for example: 905 % 10 = 5 (6th list).
}

void HashTable::Insert(int Key, string Value)   //a function to insert elements.
{
    int HashValue = HashFunction(Key);  //to know wich list the element will be in.
    auto& cell = table[HashValue];
    auto bItr = begin(cell);  //an iterator is an object that points to an element inside the container.
    bool KeyExists = false;     //to check that the key doesn't exist.
    for(; bItr != end(cell); bItr++)    //if the key exist replace the new value with the old one.
    {
        if (bItr->first == Key)
        {
            KeyExists = true;
            bItr->second = Value;
            cout<<"[WARNING] Key Exists, Value Replaced."<<endl;   
            break;
        }
    }
    if (!KeyExists)     //if the key doesn't exist.
    {
        cell.emplace_back(Key, Value);
    }

    return;
}

void HashTable::Remove(int Key)  //a function to remove an element.
{
    int HashValue = HashFunction(Key);
    auto& cell = table[HashValue];
    auto bItr = begin(cell);
    bool KeyExists = false;
    for(; bItr != end(cell); bItr++)
    {
        if (bItr->first == Key)
        {
            KeyExists = true;
            bItr = cell.erase(bItr);
            cout<<"[INFO] Pair Removed."<<endl;
            break;
        }
    }
    if(!KeyExists)  //if the element not found.
    {
        cout<< "[WARNING] Key Not Found, Pair Not Removed." <<endl;
    }

    return;
}

void HashTable::Print()     //a function to print the HT.
{
    for (int i{}; i < HashGroups; i++)
    {
        if(table[i].size() == 0)
             continue;
        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++)
        {
            cout<< "[INFO] Key: " << bItr->first << " Value: " << bItr->second <<endl;
        }
    }
    return;
}
int main()
{
    HashTable HT;   //creating a HT.

    if(HT.IsEmpty()) //if the HT is empty.
        cout<< "Corect Answer, Good Job."<<endl;
    else
        cout<< "We Nead To Check out Code"<<endl;
    
    //inserting (phone num, name)
    HT.Insert(905, "Jim");
    HT.Insert(201, "Tom");
    HT.Insert(332, "Bob");
    HT.Insert(124, "Sally");
    HT.Insert(107, "Sandy");
    HT.Insert(929, "Barb");
    HT.Insert(929, "Rob");
    HT.Insert(928, "Rick");

    HT.Print();     //print the HT.

    HT.Remove(332);
    HT.Remove(100);     //num is not in the HT.

    if(HT.IsEmpty())
            cout<< "We Nead To Check out Code"<<endl;
        else
            cout<< "Corect Answer, Good Job.";

    return 0;

}
