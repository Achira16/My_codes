#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>

int longest(int i,int dest,vector<vector<pi>>& g,vector<int>& dp,vector<int>& s)
{
    if(i == dest)
        return 0;
    if(dp[i])
        return dp[i];
    int q = INT32_MIN;
    for(int j=0;j<g[i].size();j++)
    {
        int t = g[i][j].second+longest(g[i][j].first,dest,g,dp,s);
        if(t > q)
        {
            q = t;
            s[i] = g[i][j].first;
        }
    }
    dp[i] = q;
    return dp[i];
}
void findpath(vector<int>& s,int i,int d)
{
    if(i == d)
        return;
    cout<<s[i]<<" ";
    findpath(s,s[i],d);
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<vector<pi>> graph(n);
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b,c));
    }
    vector<int> dp(n,0),s(n,-1);
    cout<<longest(0,n-1,graph,dp,s)<<"\n";
    cout<<"0 ";
    findpath(s,0,n-1);
}