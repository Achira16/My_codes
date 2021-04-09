#include<bits/stdc++.h>
using namespace std;

int longest(int i,vector<vector<int>>& g,vector<int>& dp,vector<bool>& vis)
{
    if(vis[i])
        return dp[i];
    vis[i] = true;
    if(!g[i].size())
        return 0;
    int q = INT32_MIN;
    for(int j=0;j<g[i].size();j++)
    {
        q = max(q,1+longest(g[i][j],g,dp,vis));
    }
    dp[i] = q;
    return dp[i];
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<vector<int>> graph(n);
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    vector<int> dp(n,0);
    vector<bool> vis(n,0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            longest(i,graph,dp,vis);
        }
    }
    cout<<*max_element(dp.begin(),dp.end());
}