#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int row,col,dfs_calls;

void dfs(vector<vector<int>>& mat,int r,int c,vector<vector<bool>>& vis,int n)
{
    dfs_calls++;
    if(!vis[r][c])
    {
        vis[r][c] = 1;
        if(c+1<n && mat[r][c+1])
        {
            if(!vis[r][c+1])
            {
                dfs(mat,r,c+1,vis,n);
            }
        }
        if(r+1<n && mat[r+1][c])
        {
            if(!vis[r+1][c])
            {
                dfs(mat,r+1,c,vis,n);
            }
        }
        if(c-1>=0 && mat[r][c-1])
        {
            if(!vis[r][c-1])
            {
                dfs(mat,r,c-1,vis,n);
            }
        }
        if(r-1>=0 && mat[r-1][c])
        {
            if(!vis[r-1][c])
            {
                dfs(mat,r-1,c,vis,n);
            }
        }
    }
}
int main()
{
    IOS;
    int t,n,lost;
    cin >> t;
    while(t){
    cin>>n;
    vector<vector<int>> mat(n,vector<int> (n));
    
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin >> mat[i][j];
    }
    cin>>lost;
    vector<vector<bool>> vis(n,vector<bool> (n,0));
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dfs_calls = 0;
            if(!vis[i][j] && mat[i][j])
            {
                row = i;
                col = j;
                dfs(mat,i,j,vis,n);
            }
            if(dfs_calls == lost)
            {
                cout<<row<<" "<<col<<endl;
                break;
            }
        }
    }
    t--;
    }
}