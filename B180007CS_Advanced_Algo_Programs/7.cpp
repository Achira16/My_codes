//2-approx algorithm for travelling salesman problem
#include<bits/stdc++.h>
using namespace std;
 
vector<vector<int>> mstPrim(vector<vector<int>>& graph,int source)
{
    int n = graph.size();
    vector<vector<int>> tree(n);
    vector<int> parent(n),distances(n,INT32_MAX);
    vector<bool> mst(n,false);
    mst[source] = true;
    distances[source] = 0;
    for(int i=0;i<n;i++)
    {
        if(!mst[i] && graph[source][i]<distances[i])
        {
            distances[i] = graph[source][i];
            parent[i] = source;
        }
    }
    for (int i = 1; i < n;i++)
    {
        int min_val = INT32_MAX,min_index;
        for(int j = 0; j < n; j++)
        {
            if(!mst[j] && distances[j]<min_val)
            {
                min_val = distances[j];
                min_index = j;
            }
        }
        mst[min_index] = true;
        tree[parent[min_index]].push_back(min_index);
        for(int j=0;j<n;j++)
        {
            if(!mst[j] && graph[min_index][j]<distances[j])
            {
                distances[j] = graph[min_index][j];
                parent[j] = min_index;
            }
        }
    }
    return tree;
}
void preorder(int i,vector<vector<int>>& tree,vector<int>& pre)
{
    for(auto j:tree[i])
    {
        pre.push_back(j);
        preorder(j,tree,pre);
    }
}
int tsp(int source,vector<vector<int>>& graph)
{
    int n = graph.size();
    //find out MST using Prim's algorithm
    vector<vector<int>> tree = mstPrim(graph,source);
    vector<int> pre;
    pre.push_back(source);
    //Preorder walk of the MST
    for(auto i:tree[source])
    {
        pre.push_back(i);
        preorder(i,tree,pre);
    }
    int dis = 0;
    //Calculating the total cost of the hamiltonian cycle
    cout<<"Order: ";
    for(int i=0;i<n-1;i++)
    {
        cout<<pre[i]+1<<" ";
        dis += graph[pre[i]][pre[i+1]];
    }
    cout<<pre[n-1]+1<<" "<<pre[0]+1<<endl;
    dis += graph[pre[n-1]][source];
    return dis;
}
int main()
{
    int n,d;
    cout<<"Enter the no of cities: ";
    cin >> n;
    vector<vector<int>> graph(n,vector<int> (n,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            cout<<"Enter distance from "<<i<<" to "<<j<<": ";
            cin>>d;
            graph[i-1][j-1] = d;
            graph[j-1][i-1] = d;
        }
    }
    int src;
    cout<<"Enter the source: ";
    cin>>src;
    int tour_distance = tsp(src-1,graph);
    cout<<"Total distance: "<<tour_distance;
}