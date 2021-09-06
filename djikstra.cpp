#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>

int djikstra(vector<vector<pi>>& g,int src,int dest)
{
    vector<int> dist(g.size(),INT_MAX);
    vector<bool> incl(g.size(),0);
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    pq.push({0,src});
    dist[src] = 0;
    int incl_count = 0;
    while(!pq.empty() && incl_count < g.size())
    {
        pi next = pq.top();
        pq.pop();
        int cost = next.first, u = next.second;
        incl[u] = 1;
        incl_count++;
        for(auto i:g[u])
        {
            int v = i.first,w = i.second;
            if(!incl[v] && dist[u]+w < dist[v] )
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }
    return dist[dest];
}
int main()
{
    int v;
    cin>>v;
    vector<int> members(v);
    unordered_map<int,int> vertices;
    vector<vector<pi>> g(v);
    for(int i=0;i<v;i++)
    {
        cin>>members[i];
        vertices[members[i]] = i;
    }
    int e;
    cin>>e;
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[vertices[a]].push_back({vertices[b],c});
    }
    int s,d;
    cin>>s>>d;
    cout<<djikstra(g,vertices[s],vertices[d]);
}