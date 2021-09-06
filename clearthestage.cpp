#include<bits/stdc++.h>
using namespace std;

int minsteps = 0;
bool func(vector<int>& type,vector<int>& x,int noh,int i,int n)
{
    if(i>=n)
        return 1;
    if(type[i] == 2 && noh <= x[i])
        return 0;
    else if(type[i] == 2 && noh > x[i])
        return func(type,x,noh,i+1,n);
    bool flag;
    if(type[i] == 1)
    {
        flag = func(type,x,noh,i+1,n);
        if(!flag)
        {
            flag = func(type,x,noh+x[i],i+1,n);
            if(flag)
                minsteps++;
        } 
    }
    return flag;
}
int main()
{
    int n;
    cin>>n;
    vector<int> type(n),x(n);
    for(int i=0;i<n;i++)
        cin>>type[i];
    for(int i=0;i<n;i++)
        cin>>x[i];
    func(type,x,1,0,n);
    cout<<minsteps;
}