#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<ll ,ll >pll;
typedef pair<int ,int > pii;
const ld pi=3.14159265359;
const int maxn=2e5+7;
const int mod=1e9+7;
const ll INF=9223372036854775807;
const int inf=2e9+7;

int fen[maxn];   //an array to store the elements tree.

//function to add the element x in the index number idx.
void add(int idx, int x)
{
    for(; idx <maxn; idx+=idx&-idx)
    {
        fen[idx]+=x;
    }
}

//function to return the summation of the 1st idx in the array.
int get(int idx)
{
    int ret=0;
    for(;idx; idx-=idx&-idx)
    {
        ret+=fen[idx];
    }
    return ret;
}

//function just like get except that it will return the summation of the elements in the range between L & R.
int get(int L, int R)
{
    return get(R)-get(L-1);
}

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int x,idx;
            cin>>idx>>x;
            add(idx,x);
        }
        else
        {
            int L,R;
            cin>>L>>R;
            cout<<get(L,R)<<'\n';
        }
    }
}
