//2-approx algorithm for vertex-cover problem
#include<bits/stdc++.h>
using namespace std;

void vertexCover(set<pair<int,int>>& edges)
{
    vector<int> vertices;
    while(!edges.empty())
    {
        int i = 1;
        pair<int,int> res;
        //reservoir sampling for choosing an edge. Each edge has an equal probability(1/n) of getting picked.
        for(auto it=edges.begin();it!=edges.end();it++)
        {
            int x = rand()%i;
            if(x == 0)
            {
                res = *it;
            }
            i++;
        }
        edges.erase(res);
        vertices.push_back(res.first);
        vertices.push_back(res.second);
        //remove all edges that are incident on the selected vertices.
        vector<pair<int,int>> to_remove;
        for(auto it=edges.begin();it!=edges.end();it++)
        {
            if(it->first == res.first || it->first == res.second || it->second == res.first || it->second == res.second)
            {
                to_remove.push_back(*it);
            }
        }
        for(auto i:to_remove)
        {
            edges.erase(i);
        }
    }
    for(auto v:vertices)
    {
        cout<<v<<" ";
    }
}
int main()
{
    set<pair<int,int>> edges;
    int n,a,b;
    cout<<"Enter the no. of edges: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        edges.insert(make_pair(a,b));
    }
    vertexCover(edges);
}