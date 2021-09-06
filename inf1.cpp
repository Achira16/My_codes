#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>

int func(vector<int>& p,vector<int>& b,int e)
{
    vector<pi> t;
    for(int i=0;i<p.size();i++)
    {
        t.push_back({p[i],b[i]});
    }
    sort(t.begin(),t.end());
    int count = 0;
    for(int i=0;i<t.size();i++)
    {
        if(e < t[i].first)
            break;
        e += t[i].second;
        count++;
    }
    return count;
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<int> p(n),b(n);
    for(int i=0;i<n;i++)
        cin>>p[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    cout<<func(p,b,e);
}