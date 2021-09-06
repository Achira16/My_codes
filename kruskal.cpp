#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,pair<int,int>>

struct node
{
    int parent,rank;
};
vector<node> dsuf;
int findParent(int v)
{
    if(dsuf[v].parent == -1)
        return v;
    return dsuf[v].parent = findParent(dsuf[v].parent);
}
void Union(int par1,int par2)
{
    if(dsuf[par1].rank < dsuf[par2].rank)
        dsuf[par1].parent = par2;
    else if(dsuf[par1].rank > dsuf[par2].rank)
        dsuf[par2].parent = par1;
    else
    {
        dsuf[par1].parent = par2;
        dsuf[par2].rank++;
    }     
}
struct compare
{
    bool operator()(pi &a,pi &b)
    {
        return a.first > b.first; 
    }
};

int mstcost(priority_queue<pi,vector<pi>,compare>& pq,int V)
{
    int i=0,cost = 0;
    // cout<<V-1;
    while(i < V-1)
    {
        pi next = pq.top();
        pq.pop();
        // cout<<next.second.first<<" "<<next.second.second<<endl;
        int par1 = findParent(next.second.first),par2 = findParent(next.second.second);
        if(par1 == par2)
            continue;
        // cout<<next.first<<endl;
        Union(par1,par2);
        cost += next.first;
        i++;
    }
    return cost;
}
int main()
{
    int V,E;
    cin>>V>>E;
    dsuf.resize(V);
    for(int i=0;i<V;i++)
    {
        dsuf[i].parent = -1;
        dsuf[i].rank = 0;
    }
    priority_queue<pi,vector<pi>,compare> pq;
    while(E--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        pq.push({w,{u,v}});
    }
    cout<<mstcost(pq,V);
}