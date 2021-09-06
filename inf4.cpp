#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

ll func(int i,int j,int mat[][2],int n,vector<vector<ll>>& dp)
{
    if(i == n-1)
        return mat[i][j];
    if(dp[i][j] != -1)
        return dp[i][j];
    ll cost = mat[i][j],t1 = 0,t2 = 0;
    if(mat[i+1][0] > mat[i][j])
        t1 = func(i+1,0,mat,n,dp);
    if(mat[i+1][1] > mat[i][j])
        t2 = func(i+1,1,mat,n,dp);
    cost = (cost%mod + max(t1,t2)%mod)%mod;
    dp[i][j] = cost;
    return cost;
}
ll func(int mat[][2],int n)
{
    vector<vector<ll>> dp(n,vector<ll> (2,-1));
    dp[0][0] = mat[0][0];
    dp[0][1] = mat[0][1];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            if(mat[i][j] > mat[i-1][0] && dp[i-1][0]!=-1)
                dp[i][j] = mat[i][j]+dp[i-1][0];
            if(mat[i][j] > mat[i-1][1] && dp[i-1][1]!=-1)
                dp[i][j] = max(dp[i][j],mat[i][j]+dp[i-1][1]);
        }
        if(dp[i][0] == -1 && dp[i][1] == -1)
            return max(dp[i-1][0],dp[i-1][1]);
    }
    return max(dp[n-1][0],dp[n-1][1]);
}
int main()
{
    int n;
    cin>>n;
    int mat[n][2];
    for(int i=0;i<n;i++)
    {
        cin>>mat[i][0];
        cin>>mat[i][1];
    }
    vector<vector<ll>> dp(n,vector<ll> (2,-1));
    ll cost = max(func(0,0,mat,n,dp),func(0,1,mat,n,dp));
    cout<<cost;
    cout<<func(mat,n);
}