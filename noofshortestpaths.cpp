#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>

vector<int> bfs(vector<vector<int>> g,int src,int v)
{
    vector<int> min_dist(v+1,INT_MAX),path(v+1,0),vis(v+1,0);
    min_dist[src] = 0;
    path[src] = 1;
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        if(src == v && par == 1)
            continue;
        else if(src == 1 && par == v)
            continue;
        for(auto i:g[par])
        {
            if(!vis[i])
            {
                vis[i] = 1;
                q.push(i);
            }
            if(min_dist[par]+1 < min_dist[i])
            {
                min_dist[i] = min_dist[par]+1;
                path[i] = path[par];
            }
            else if(min_dist[par]+1 == min_dist[i])
                path[i] += path[par];
        }
    }
    return path;
}

int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<int>> g(v+1);
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> temp1 = bfs(g,1,v);
    vector<int> temp2 = bfs(g,v,v);
    for(int i:temp1)
    {
        cout<<i<<" ";
    }
    for(int i:temp2)
    {
        cout<<i<<" ";
    }
}