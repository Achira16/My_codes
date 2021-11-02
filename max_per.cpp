#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define pi pair<int,int>

int power(int n){
    int ans = 1,x = 2;
    while(n){
        if(n&1) ans*=x;
        n >>= 1;
        x*=x;
    }
    return ans;
}
pi func(vector<int>& arr,int prev,int mask,int num, vector<vector<pi>>& dp){
    int n = __builtin_popcount(mask);
    if(n == num) return {arr[prev],1};
    pi def = {-1,0};
    if(dp[prev][mask]!=def) return dp[prev][mask];
    int ans = 0;
    for(int j=1;j<=num;j++){
        if((mask & (1<<j)) == 0){
            pi temp = func(arr,j,mask | (1<<j),num, dp);
            int t = abs(arr[j]-arr[prev]) + temp.first;
            if(t > ans)
                dp[prev][mask].second = temp.second;
            else if(t == ans)
                dp[prev][mask].second += temp.second;
            ans = max(ans,t);
        }
    }
    dp[prev][mask].first = ans;
    return dp[prev][mask];
}
int main(){
    IOS;
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> arr(n+1);
        for(int i=0;i<n;i++)
            cin>>arr[i+1];
        arr[0] = 0;
        int max_mask = power(n+1);
        vector<vector<pi>> dp(n+1,vector<pi> (max_mask,{-1,0}));
// vector<vector<int>> counts(20,vector<int> (65535));
        pi ans = func(arr,0,0,n, dp);
        cout<<ans.first+2*n<<" "<<ans.second<<endl;
    }
}