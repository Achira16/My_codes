#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct node
{
    int val,i,j;
    node(int v,int i,int j):val(v),i(i),j(j){}
};
struct compare
{
    bool operator()(node const& a,node const& b)
    {
        return a.val < b.val;
    }
};
long solve(vector<vector<int>>& mat,int r,int c)
{
    vector<vector<int>> vis(r,vector<int> (c,0));
    priority_queue<node,vector<node>,compare> pq;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            pq.push(node(mat[i][j],i,j));
        }
    }
    int dir[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    long count = 0;
    while(!pq.empty())
    {
        node next = pq.top();
        pq.pop();
        int i = next.i,j = next.j,val = next.val;
        if(!vis[i][j] && val == mat[i][j])
        {
            vis[i][j] = 1;
            for(int k=0;k<4;k++)
            {
                int next_i = i+dir[k][0],next_j = j+dir[k][1];
                if(next_i>=0 && next_i<r && next_j>=0 && next_j<c)
                {
                    if(abs(val-mat[next_i][next_j]) > 1)
                    {
                        count += abs(val-mat[next_i][next_j]-1);
                        mat[next_i][next_j] += abs(val-mat[next_i][next_j]-1);
                        pq.push(node(mat[next_i][next_j],next_i,next_j));
                    }
                }
            }
        }
    }
    return count;
}
int main()
{
    IOS;
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int>> mat(r,vector<int> (c));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                cin>>mat[i][j];
        }
        cout<<"Case #"<<t<<": "<<solve(mat,r,c)<<"\n";
    }
}