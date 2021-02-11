#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int row,col,dfs_calls,n;

void dfs(vector<vector<int>>& mat,int r,int c,vector<vector<bool>>& vis)
{
    dfs_calls++;
    if(!vis[r][c])
    {
        vis[r][c] = 1;
        int dir[][2] = {{-1,0},{-1,-1},{0,-1},{0,1},{1,0},{1,1},{-1,1},{1,-1}};
        for(int i=0;i<8;i++)
        {
            if((r+dir[i][0]>=0 && r+dir[i][0]<n) && (c+dir[i][1]>=0 && c+dir[i][1]<n) && mat[r+dir[i][0]][c+dir[i][1]])
            {
                if(!vis[r+dir[i][0]][c+dir[i][1]])
                {
                    dfs(mat,r+dir[i][0],c+dir[i][1],vis);
                }
            }
        }
    }
}
int main()
{
    IOS;
    int t;
    cin >> t;
    while(t){
    cin>>n;
    vector<vector<int>> mat(n,vector<int> (n));
    
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin >> mat[i][j];
    }
    vector<vector<bool>> vis(n,vector<bool> (n,0));
    int ans = 0;
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dfs_calls = 0;
            if(!vis[i][j] && mat[i][j])
            {
                row = i;
                col = j;
                dfs(mat,i,j,vis);
            }
            ans = max(ans,dfs_calls);
        }
    }
    cout<<ans<<endl;
    t--;
    }
}