#include<bits/stdc++.h>
using namespace std;
int main()
{
    set<int> a;
    for (int i = 0; i <10;i++)  
        a.insert(i);
    vector<int> to_remove;
    for(auto it=a.begin();it!=a.end();it++)
    {
        if(*it & 1)
        {
            to_remove.push_back(*it);
        }
    }
    for(auto it:to_remove)
    {
        a.erase(it);
    }
    for(auto it=a.begin();it!=a.end();it++)
    {
        cout<<*it<<" ";
    }
}