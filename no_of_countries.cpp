#include<bits/stdc++.h>
using namespace std;
void dfs(int i,vector<vector<int>>& graph,vector<bool>& vis)
{
    if(!vis[i])
    {
        vis[i] = true;
        for(auto it:graph[i])
        {
            if(!vis[it])
            {
                dfs(it,graph,vis);
            }
        }
    }
}
int main()
{
    int n,p,p1,p2;
    cin>>n>>p;
    vector<vector<int>> graph(n);
    for(int i=0;i<p;i++)
    {
        cin>>p1>>p2;
        graph[p1].push_back(p2);
        graph[p2].push_back(p1);
    }
    vector<bool> vis(n,0);
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            count++;
            dfs(i,graph,vis);
        }
    }
    cout<<count;
}