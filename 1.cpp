#include<bits/stdc++.h>
using namespace std;

bool func(vector<vector<int>>& g,int src,int dest)
{
    vector<bool> vis(g.size(),0);
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v:g[u])
        {
            if(v == dest)
                return true;
            if(!vis[v])
            {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    return false;
}
int main()
{
    int v;
    cin>>v;
    vector<int> members(v);
    unordered_map<int,int> vertices;
    vector<vector<int>> g(v);
    for(int i=0;i<v;i++)
    {
        cin>>members[i];
        vertices[members[i]] = i;
    }
    int e;
    cin>>e;
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        g[vertices[a]].push_back(vertices[b]);
    }
    int s,d;
    cin>>s>>d;
    vector<int> res;
    cout<<func(g,vertices[s],vertices[d]);
}