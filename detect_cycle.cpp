#include<bits/stdc++.h>
using namespace std;

bool detect_cycle_util(int i,vector<vector<int>>& undir_graph,bool vis[],int par = -1)
{
    vis[i] = true;
    for(auto it=undir_graph[i].begin();it!=undir_graph[i].end();it++)
    {
        if(!vis[*it])
        {
            if(detect_cycle_util(*it,undir_graph,vis,i))
                return true;
        }
        else if (*it != par)
            return true;
    }
    return false;
}
bool detect_cycle1(vector<vector<int>>& undir_graph)
{
    bool vis[undir_graph.size()];
    memset(vis,0,sizeof(vis));
    for(int i=0;i<undir_graph.size();i++)
    {
        if(!vis[i] && detect_cycle_util(i,undir_graph,vis))
            return true;
    }
    return false;
}
bool detect_cycle_util(int i,vector<vector<int>>& dir_graph,bool vis[],bool recstack[])
{
    vis[i] = true;
    recstack[i] = true;
    for(auto it=dir_graph[i].begin();it!=dir_graph[i].end();it++)
    {
        if(!vis[*it] && detect_cycle_util(*it,dir_graph,vis,recstack))
            return true;
        else if (recstack[*it])
            return true;
    }
    recstack[i] = false;
    return false;
}
bool detect_cycle(vector<vector<int>>& dir_graph)
{
    bool vis[dir_graph.size()];
    bool recstack[dir_graph.size()];
    memset(vis,0,sizeof(vis));
    memset(recstack,0,sizeof(recstack));
    for(int i=0;i<dir_graph.size();i++)
    {
        if(!vis[i] && detect_cycle_util(i,dir_graph,vis,recstack))
            return true;
    }
    return false;
}
void create_graph(vector<vector<int>>& dir_graph)
{
    int e,u,v;
    cin>>e;
    for(int i=0;i<e;i++)
    {
        cin>>u>>v;
        dir_graph[u].push_back(v);
    }
}
void create_graph1(vector<vector<int>>& undir_graph)
{
    int e,u,v;
    cin>>e;
    for(int i=0;i<e;i++)
    {
        cin>>u>>v;
        undir_graph[u].push_back(v);
        undir_graph[v].push_back(u);
    }
}
int main()
{
   int n;
   //cin>>n;
   
  /* vector<vector<int>> dir_graph(n);
   create_graph(dir_graph);
   if(detect_cycle(dir_graph))
        cout<<"Cycle detected";*/
    cin>>n;
    vector<vector<int>> undir_graph(n);
    create_graph1(undir_graph);
   if(detect_cycle1(undir_graph))
        cout<<"Cycle detected";
}