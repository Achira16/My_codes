#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<int> adj[],int n,int src,int dest,int c,int t){
    vector<int> dist(n,INT_MAX);
    dist[src] = 0;
    vector<int> paths(n);
    paths[src] = 1;
    vector<bool> vis(n);
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v:adj[u]){
            if(!vis[v] && v != dest){
                vis[v] = 1;
                q.push(v);
            }
            int weight = dist[u] + c;
            weight += ((weight/t) & 1)? t-weight%t : 0;
            if(weight < dist[v]){
                dist[v] = weight;
                paths[v] = paths[u];
            } 
            else if(weight == dist[v])
                paths[v] += paths[u];
        }
    }
    return paths;
}
int main(){
    int n,m,t,c;
    cin>>n>>m>>t>>c;
    vector<int> graph[n];
    while (m--)
    {
        int u,v;
        cin>>u>>v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    vector<int> paths1 = bfs(graph,n,0,n-1,c,t);
    vector<int> paths2 = bfs(graph,n,n-1,0,c,t);
    for(int i=0;i<n;i++){
        cout<<paths1[i]*paths2[i]<<" ";
    }
}