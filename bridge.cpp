#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n";
#define pi pair<int,int>

int solve(int i,vector<pi>& arr,int cost,int n,vector<int>& dp)
{
    if(dp[i])
        return dp[i];
    if(arr[i].second == n)
    {
        dp[i] = arr[i].second-arr[i].first+1;
        return cost+dp[i];
    }
    if(i >= arr.size()-1 && arr[i].second!=n)
    {
        dp[i] = INT_MAX;
        return dp[i];
    }
    int cur_cost = INT_MAX,c = arr[i].second-arr[i].first+1;
    for(int j=i+1;j<arr.size();j++)
    {
        int temp_cost = solve(j,arr,c,n,dp);
        cur_cost = min(temp_cost,cur_cost);
    }
    if(cur_cost == INT_MAX)
    {
        dp[i] = cur_cost;
        return dp[i];
    }
    dp[i] = cost+cur_cost;
    return dp[i];
}
int main()
{
    IOS;
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        vector<pi> teams(m);
        for(int i=0;i<m;i++)
        {
            cin>>teams[i].first;
            cin>>teams[i].second;
        }
        sort(teams.begin(), teams.end());
        int cost = INT_MAX;
        vector<int> dp(m,0);
        for(int i=0;i<m;i++)
        {
            if(teams[i].first == 1)
                cost = min(cost,solve(i,teams,0,n,dp));
        }
        if(cost == INT_MAX)
        {
            cout<<-1<<endl;
        }   
        else
        {
            cout<<cost<<endl;
        }    
    }
}