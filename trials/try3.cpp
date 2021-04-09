#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(a == 0)
        return b;
    return gcd(b%a,a);
}
int ans = 0;
vector<vector<int>> dp(30,vector<int> (30,0));
int dfs(int prev,int count,int i,int num,vector<bool>& vis,vector<vector<bool>>& mat,vector<int>& arr){
    vis[i] = 1;
    if(prev!=-1 && dp[prev][i]) 
        return dp[prev][i];
    int x = 0;
    if(count == 2)
        x = gcd(x,arr[prev]+arr[i]);
    for(int j=0;j<mat.size();j++){
        if(mat[i][j] && !vis[j]){
            if(count == 2)
            {
                x = gcd(x,dfs(-1,1,j,num,vis,mat,arr));
            }
            else
            {
                x = max(x,dfs(i,count+1,j,num+1,vis,mat,arr));
            }    
            if(count == 2){
            vis[i] = 0;
            dp[prev][i] = x;
            return x;
            }
        }
    }
    vis[i] = 0;
    return x;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<vector<bool>> mat(n,vector<bool> (n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j)    
                mat[i][j] = 1;
        }
    }
    vector<bool> vis(n,0);
    int count = 1,src = 0;
    vis[src] = 1;
    int num = 0;
    for(int j=0;j<n;j++){
        if(mat[src][j] && !vis[j]){
            dp[0][j] = max(dp[0][j],dfs(src,count+1,j,num+1,vis,mat,arr));
        }     
        ans = max(ans,dp[0][j]);
    }
    cout<<ans;
}