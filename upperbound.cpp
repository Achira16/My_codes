#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {1,2,4,8,5};
    set<int> s(a.begin(),a.end());
    if(s.upper_bound(8) == s.end())
    {
        cout<<"no element bigger than this";
    }
    else
        cout<<*s.upper_bound(8);
}