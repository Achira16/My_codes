#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
struct node
{
    int i,j,val;
};
int fireInTheCells(vector<vector<int>> &mat, int n, int m, int x, int y) {
    // Write your code here.
    vector<vector<bool>> vis(n,vector<bool> (m,0));
    vector<vector<int>> times(n,vector<int> (m,0));
    queue<node> q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!mat[i][j])
            {
                q.push({i,j,0});
                vis[i][j] = 1;
            }
        }
    }
    int t = 0;
    int dir[][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    while(!q.empty())
    {
        while(q.front().val == t)
        {
            node next = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int next_i = next.i+dir[i][0],next_j = next.j+dir[i][1];
                if(next_i>=0 && next_i<n && next_j>=0 && next_j<m)
                {
                    if(!vis[next_i][next_j])
                    {
                        vis[next_i][next_j] = 1;
                        times[next_i][next_j] = next.val+1;
                        q.push({next_i,next_j,times[next_i][next_j]});
                    }
                }
            }
        }
        t++;
    }
    q.push({x,y,1});
    if((x==0 ^ y==0) || (x==n-1 ^ y==m-1))
        return 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            vis[i][j] = 0;
    vis[x][y] = 1;
    while(!q.empty())
    {
        node next = q.front();
        q.pop();
        // cout<<next.i<<" "<<next.j<<"\n";
        for(int i=0;i<4;i++)
        {
            int next_i = next.i+dir[i][0],next_j = next.j+dir[i][1];
            if(next_i>=0 && next_i<n && next_j>=0 && next_j<m)
            {
                if(!vis[next_i][next_i])
                {
                    vis[next_i][next_j] = 1;
                    if(times[next_i][next_j] > next.val)
                    {
                        if((next_i==0 ^ next_j==0) || (next_i==n-1 ^ next_j==m-1))
        					return next.val;
                        q.push({next_i,next_j,next.val+1});
                    }
                }
            }
        }
    }
    return -1;
}
int main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n,vector<int> (m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>mat[i][j];
    }
    int x,y;
    cin>>x>>y;
    cout<<fireInTheCells(mat,n,m,x,y)<<"\n";
    }
}