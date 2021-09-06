#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi pair<int,pair<int,int>>

struct node
{
    int parent,rank;
};
vector<node> dsuf;

int findParent(int v)
{
    if(dsuf[v].parent == -1)
        return v;
    return dsuf[v].parent = findParent(dsuf[v].parent);
}
void Union(int par1,int par2)
{
    if(dsuf[par1].rank < dsuf[par2].rank)
        dsuf[par1].parent = par2;
    else if(dsuf[par1].rank > dsuf[par2].rank)
        dsuf[par2].parent = par1;
    else
    {
        dsuf[par1].parent = par2;
        dsuf[par2].rank++;
    }     
}

long solve(priority_queue<pi>& pq,int edges,int V,int total)
{
    dsuf.resize(V);
    for(int i=0;i<V;i++)
    {
        dsuf[i].parent = -1;
        dsuf[i].rank = 0;
    }
    long cost = 0;
    int i = 0;
    while(i<edges-1)
    {
        pi next = pq.top();
        pq.pop();
        int par1 = findParent(next.second.first),par2 = findParent(next.second.second);
        if(par1 == par2)
            continue;
        Union(par1,par2);
        cost += next.first;
        i++;
    }
    return total-cost;
}
int main()
{
    IOS;
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int n;
        cin>>n;
        vector<vector<int>> mat(n,vector<int> (n));
        vector<vector<int>> B(n,vector<int> (n));
        vector<int> rows(n),cols(n);
        priority_queue<pi> pq;
        long total = 0;
        unordered_set<int> vert;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>B[i][j];
                if(mat[i][j] == -1)
                {
                    vert.insert(i);
                    vert.insert(n+j);
                    total += B[i][j];
                    pq.push({B[i][j],{i,n+j}});
                }
            }
        }
        for(int i=0;i<n;i++)
            cin>>rows[i];
        for(int i=0;i<n;i++)
            cin>>cols[i];   
        cout<<"Case #"<<t<<": "<<solve(pq,vert.size(),2*n,total)<<"\n";
    }
}