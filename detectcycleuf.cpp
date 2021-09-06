//Detect cycle using union find operations (Time complexity:O(V*E))
#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>

vector<int> parent;
int findParent(int v)
{
    if(parent[v] == -1)
        return v;
    return findParent(parent[v]);
}
bool isCyclic(vector<pi>& edgeList)
{
    for(auto p:edgeList)
    {
        int u = p.first,v = p.second;
        int abspar_u = findParent(u),abspar_v = findParent(v);
        if(abspar_u == abspar_v)
            return true;
        parent[abspar_u] = abspar_v;
    }
    return false;
}
int main()
{
    int V,E;
    cin>>V>>E;
    parent.resize(V,-1);
    vector<pi> edgeList;
    while(E--)
    {
        int u,v;
        cin>>u>>v;
        edgeList.push_back({u,v});
    }
    cout<<isCyclic(edgeList);
}