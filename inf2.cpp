#include<bits/stdc++.h>
using namespace std;
#define mod 10000
#define ll long long

ll func(int i,int n,int k,int ind,vector<vector<int>>& dp)
{
    if(ind == k-1)
        return 1;
    if(dp[i][ind] != -1)
        return dp[i][ind];
    ll count = 0;
    for(int j=i;j<=n;j++)
    {
        if(j%i == 0)
        {
            count = (count%mod + func(j,n,k,ind+1,dp)%mod)%mod;
        }
    }
    dp[i][ind] = count%mod;
    return dp[i][ind];
}
int main()
{
    int n,k;
    cin>>n>>k;
    ll count = 0;
    vector<vector<int>> dp(n+1,vector<int> (k,-1));
    for(int i=1;i<=n;i++)
    {
        count = (count%mod + func(i,n,k,0,dp)%mod)%mod;
    }
    cout<<count;
}