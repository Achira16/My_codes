#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main(){
    int m,n;
    cin>>m>>n;
    vector<int> cap(m);
    for(int i=0;i<m;i++)
        cin>>cap[i];
    vector<vector<long>> dp(m+1,vector<long> (n+1,0));
    for(int i=0;i<=m;i++)
        dp[i][0] = 1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(cap[i-1] <= j){
                dp[i][j] = (dp[i-1][j]%mod + dp[i][j-cap[i-1]]%mod)%mod;
            }
            else
                dp[i][j] = dp[i-1][j]%mod;
        }
    }
    cout<<dp[m][n]%mod;
}   