#include<bits/stdc++.h>
using namespace std;

int count(int n){
    vector<vector<int>> dp(n,vector<int> (6));
    dp[0][0] = 5;
    for(int i=1;i<6;i++)
        dp[0][i] = 1;
    for(int i=1;i<n;i++){
        int sum = 0;
        for(int j=1;j<6;j++){
            if(j == 1)
                dp[i][j] = dp[i-1][0];
            else{
                dp[i][j] = dp[i][j-1]-dp[i-1][j-1];
            }
            sum+=dp[i][j];
        }
        dp[i][0] = sum;
    }
    return dp[n-1][0];
}
int main(){
    int n;
    cin>>n;
    cout<<count(n);
}