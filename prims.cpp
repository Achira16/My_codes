#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>

class Solution{
	public:
	// Function to construct and print MST for
    // a graph represented using adjacency
    // list representation, with V vertices.
    int spanningTree(int V, vector<vector<pi>> adj) {
        vector<int> keys(V,INT_MAX),mst(V,0);
        keys[0] = 0;
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.push({keys[0],0});
        int cost = 0,incl_count = 0;
        while(!pq.empty() && incl_count<V)
        {
            pi next = pq.top();
            pq.pop();
            int u = next.second;
            if(!mst[u])
            {
                mst[u] = 1;
                incl_count++;
                cost += next.first;
                for(auto v:adj[u])
                {
                    if(!mst[v.first] && v.second < keys[v.first])
                    {
                        keys[v.first] = v.second;
                        pq.push({keys[v.first],v.first});
                    }
                }
            }
        }
        // cout<<cost;
        return cost;
    }
};
int main()
{
    int V,E;
    cin>>V>>E;
    vector<vector<pi>> adj(V);
    while(E--)
    {
        int u ,v, w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    Solution obj;
    cout<<obj.spanningTree(V,adj)<<"\n";
}