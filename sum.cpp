#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int func(int n,int k)
{
    vector<int> dp(n+1,0);
    dp[0] = 1;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i <= j)
                dp[j] = (dp[j]%mod + dp[j-i]%mod)%mod;
        }
    }
    return dp[n];
}

int main()
{
    int n,k;
    cin>>n>>k;
    cout<<func(n,k);
}