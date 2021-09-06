#include<bits/stdc++.h>
using namespace std;
#define ll long long

int func(int i,vector<int>& arr,int N,int k,vector<vector<int>>& dp)
{
    if(i >= N) return 0;
    if(k == 1) return arr[i]+arr[N-1];
    if(dp[N-i][k] != -1) return dp[N-i][k];
    int ans = INT_MIN;
    for(int j=i;j<=N-k;j++)
    {
        int temp = arr[i]+arr[j];
        temp += func(j+1,arr,N,k-1,dp);
        ans = max(ans,temp);
    }
    dp[N-i][k] = ans;
    return ans;
}
int func1(int i,vector<int>& arr,int N,int k,vector<vector<int>>& dp)
{
    if(i >= N) return 0;
    if(k == 1) return arr[i]+arr[N-1];
    if(dp[N-i][k] != -1) return dp[N-i][k];
    int ans = INT_MAX;
    for(int j=i;j<=N-k;j++)
    {
        int temp = arr[i]+arr[j];
        temp += func1(j+1,arr,N,k-1,dp);
        ans = min(ans,temp);
    }
    dp[N-i][k] = ans;
    return ans;
}
ll candies_diff(vector<int>& arr,int n,int k)
{
    vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
    int alice = func(0,arr,n,k,dp);
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
            dp[i][j] = -1;
    }
    int bob = func1(0,arr,n,k,dp);
    return alice-bob;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<candies_diff(arr,n,k);
}