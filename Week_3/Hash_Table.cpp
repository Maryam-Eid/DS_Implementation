#include <iostream>
#include <list>
#include <cstring>
using namespace std;

class HashTable
{
    private:
        static const int HashGroups =10;
        list<pair<int, string>> table[HashGroups];  //list 1, indix 0, list 2, index 1...
    public:
        bool IsEmpty() const;
        int HashFunction(int Key);
        void Insert(int Key, string Value);
        void Remove(int Key);
        string Search(int Key);
        void Print();
};

 bool HashTable::IsEmpty() const
{
    int Sum{};
    for (int i{}; i < HashGroups; i++)
        Sum += table[i].size();

    if (!Sum)
        return true;
    return
        false;
}

int HashTable::HashFunction(int Key)
{
    return Key % HashGroups;    //905 % 10 = 5.
}

void HashTable::Insert(int Key, string Value)
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
            bItr->second = Value;
            cout<<"[WARNING] Key Exists, Value Replaced."<<endl;
            break;
        }
    }
    if (!KeyExists)
    {
        cell.emplace_back(Key, Value);
    }

    return;
}

void HashTable::Remove(int Key)
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
    if(!KeyExists)
    {
        cout<< "[WARNING] Key Not Found, Pair Not Removed." <<endl;
    }

    return;
}

void HashTable::Print()
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
    HashTable HT;

    if(HT.IsEmpty())
        cout<< "Corect Answer, Good Job."<<endl;
    else
        cout<< "We Nead To Check out Code"<<endl;

    HT.Insert(905, "Jim");
    HT.Insert(201, "Tom");
    HT.Insert(332, "Bob");
    HT.Insert(124, "Sally");
    HT.Insert(107, "Sandy");
    HT.Insert(929, "Barb");
    HT.Insert(929, "Rob");
    HT.Insert(928, "Rick");

    HT.Print();

    HT.Remove(332);
    HT.Remove(100);

    if(HT.IsEmpty())
            cout<< "We Nead To Check out Code"<<endl;
        else
            cout<< "Corect Answer, Good Job.";

    return 0;

}