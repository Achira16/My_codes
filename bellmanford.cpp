#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>

int bellmanFord(vector<vector<pi>>& g,int src,int dest)
{
    vector<int> dist(g.size(),INT_MAX);
    vector<bool> incl(g.size(),0);
    dist[src] = 0;
    for(int i=1;i<g.size();i++)
    {
        bool flag = false;
        for(int u=0;u<g.size();u++)
        {
            for(auto v:g[u])
            {
                if(dist[u]!=INT_MAX && dist[u]+v.second < dist[v.first])
                {
                    dist[v.first] = dist[u]+v.second;
                    flag = true;
                }
            }
        }
        if(!flag)
            return dist[dest];
    }
    bool f = false;
    for(int u=0;u<g.size();u++)
        {
            for(auto v:g[u])
            {
                if(dist[u]!=INT_MAX && dist[u]+v.second < dist[v.first])
                {
                    dist[v.first] = dist[u]+v.second;
                    f = true;
                }
            }
        }
    if(f)
        return -1;
    return dist[dest];
}
int main()
{
    int v;
    cin>>v;
    vector<vector<pi>> g(v);
    int e;
    cin>>e;
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
    }
    int s,d;
    cin>>s>>d;
    cout<<bellmanFord(g,s,d);
}