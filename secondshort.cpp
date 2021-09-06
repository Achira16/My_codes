#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>

vector<pi> bfs(vector<vector<int>> g,int src,int v)
{
    vector<pi> min_dist(v+1,{INT_MAX,-1});
    vector<int> vis(v+1,0);
    min_dist[src] = {0,-1};
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
            if(min_dist[par].first+1 < min_dist[i].first)
            {
                min_dist[i].first = min_dist[par].first+1;
                min_dist[i].second = par;
            }
        }
    }
    return min_dist;
}
int bfs1(vector<vector<int>>& g,int t,int c,int src,int v)
{
    int cost = INT_MAX,temp_cost = 0;
    vector<int> vis(v+1,0);
    queue<int> q;
    q.push(1);
    vis[src] = 1;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        for(auto i:g[temp])
        {
            if(!vis[i])
            {
                if(i == v)
                {
                    temp_cost+=c;
                    cost = min(cost,temp_cost);
                    break;
                }
                vis[i] = 1;
                q.push(i);
            }
            
        }
        temp_cost += c;
        int x = temp_cost/t;
        if(x&1)
            temp_cost += t-c%t;
    }
    return cost;
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
    // vector<pi> temp1 = bfs(g,1,v);
    // vector<pi> temp2 = bfs(g,v,v);
    // for(int i:temp1)
    // {
    //     cout<<i<<" ";
    // }
    // for(int i:temp2)
    // {
    //     cout<<i<<" ";
    // }
    cout<<bfs1(g,3,3,1,v);
}