#include<bits/stdc++.h>
using namespace std;

int func(vector<int>& arr,int i,int j,vector<vector<int>>& dp)
{
    if(j < i)
        return 0;
    if(i == j)
        return arr[i];
    else if(j == i+1)
        return max(arr[i],arr[j]);
    if(dp[i][j] != -1)
        return dp[i][j];
    int ans1 = arr[i] + max(func(arr,i+2,j,dp),func(arr,i+1,j-1,dp));
    int ans2 = arr[j] + max(func(arr,i+1,j-1,dp),func(arr,i,j-2,dp));
    dp[i][j] = max(ans1,ans2);
    return dp[i][j];
}
int main()
{
    // int n;
    // cin>>n;
    // vector<int> arr(n);
    // for(int i=0;i<n;i++)
    //     cin>>arr[i];
    // vector<vector<int>> dp(n,vector<int> (n,-1));
    // cout<<func(arr,0,n-1,dp);
    int n = -10;
    cout<<to_string(n);
}