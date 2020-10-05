#include<bits/stdc++.h>
using namespace std;

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
    for(int i=0;i<dir_graph.size();i++)
    {
        if(!vis[i] && detect_cycle_util(i,dir_graph,vis,recstack))
            return true;
    }
    return false;
}
void topo_sort_util(int i,vector<vector<int>>& graph,bool vis[],stack<int>& st)
{
    vis[i] = true;
    for(auto it=graph[i].begin();it!=graph[i].end();it++)
    {
        if(!vis[*it])
            topo_sort_util(*it,graph,vis,st);
    }
    st.push(i);
}
void topo_sort(vector<vector<int>>& graph)
{
    bool vis[graph.size()];
    memset(vis,0,sizeof(vis));
    stack<int> st;
    for(int i=0;i<graph.size();i++)
    {
        if(!vis[i])
            topo_sort_util(i,graph,vis,st);
    }
    int n = st.size();
    for(int i=0;i<n;i++)
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}
void create_graph(vector<vector<int>>& graph)
{
    int e,u,v;
    cin>>e;
    for(int i=0;i<e;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
    }
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> graph(n);
    create_graph(graph);
    if(detect_cycle(graph))
    {
         cout<<"Cycle";
         return -1;
    }
    topo_sort(graph);
}