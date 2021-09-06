#include<bits/stdc++.h>
using namespace std;

void func(vector<vector<int>>& g,int src,int dest,vector<int>& res)
{
    queue<int> q;
    q.push(src);
    vector<bool> vis(g.size(),0);
    vis[src] = 1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v:g[u])
        {
            if(!vis[v])
            {
                vis[v] = 1;
                if(v == dest)
                    res.push_back(u);
                else
                    q.push(v);
            }
            else if(v == dest)
                res.push_back(u);
        }
    }
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
    func(g,vertices[s],vertices[d],res);
    for(int i=0;i<res.size();i++)
    {
        res[i] = members[res[i]];
    }
    sort(res.begin(),res.end());
     for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
}