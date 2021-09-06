//Detect cycle using union find operations (Time complexity:O(Elog(V)))
#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>

struct node
{
    int parent,rank;
};

vector<node> dfus;
int findParent(int v)
{
    if(dfus[v].parent == -1)
        return v;
    return dfus[v].parent = findParent(dfus[v].parent);
}
void Union(int par1,int par2)
{
    if(dfus[par1].rank < dfus[par2].rank)
        dfus[par1].parent = par2;
    else if(dfus[par1].rank > dfus[par2].rank)
        dfus[par2].parent = par1;
    else
    {
        dfus[par1].parent = par2;
        dfus[par2].rank++;
    }     
}
bool isCyclic(vector<pi>& edgeList)
{
    for(auto p:edgeList)
    {
        int u = p.first,v = p.second;
        int abspar_u = findParent(u),abspar_v = findParent(v);
        if(abspar_u == abspar_v)
            return true;
        Union(abspar_u,abspar_v);
    }
    return false;
}
int main()
{
    int V,E;
    cin>>V>>E;
    dfus.resize(V);
    for(int i=0;i<V;i++)
    {
        dfus[i].parent = -1;
        dfus[i].rank = 0;
    }
    vector<pi> edgeList;
    while(E--)
    {
        int u,v;
        cin>>u>>v;
        edgeList.push_back({u,v});
    }
    cout<<isCyclic(edgeList);
}