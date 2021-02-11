#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b)
    {
        return (a[0]<b[0] ||a[0]==b[0] && a[1]<b[1]);
    }
    int bsearch(vector<vector<int>>& events,int l,int h,int e)
    {
        while(l<=h)
        {
            int mid = (l+h)/2;
            if(events[mid][0] <= e)
                l = mid+1;
            else
                h = mid-1;
        }
        return l;
    }
    int solve(int profit,int i,int k,vector<vector<int>>& events,vector<vector<int>>& dp)
    {
        int n = events.size();
        if(i>=n || k==0)
            return 0;
        if(dp[i][k-1])
            return dp[i][k-1];
        int j = bsearch(events,i+1,n-1,events[i][1]);
        dp[i][k-1] = max(solve(profit,i+1,k,events,dp),events[i][2]+solve(profit,j,k-1,events,dp));
        return dp[i][k-1];
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end(),cmp);
        vector<vector<int>> dp(events.size(),vector<int> (k,0));
        return solve(0,0,k,events,dp);
    }
};

int main()
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>> arr(n,vector<int> (3));
    for(int i=0;i<n;i++)
    {
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    Solution obj;
    cout<<obj.maxValue(arr,k);
}