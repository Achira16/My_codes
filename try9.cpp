#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(a == 0)
        return b;
    return gcd(b%a,a);
}
int solve(vector<int> arr,int sum,vector<int>& dp){
    if(arr.size() == 2){
        return gcd(0,arr[0]+arr[1]);
    }
    if(dp[sum])
        return dp[sum];
    vector<int> new_arr;
    int ind1 = 0;
    int X = 0;
    for(int i=1;i<arr.size();i++){
        int x = gcd(0,arr[ind1]+arr[i]);
        for(int j=0;j<arr.size();j++){
            if(j!=ind1 && j!=i){
                new_arr.push_back(arr[j]);
            }
        }     
        int temp = sum - (arr[ind1]+arr[i]);  
        x = gcd(x,solve(new_arr,temp,dp));
        X = max(X,x);
    }
    dp[sum] = X;
    return X;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int sum = 0;
    for(int i=0;i<arr.size();i++)
        sum+=arr[i];
    vector<int> dp(sum,0);
    cout<<solve(arr,sum,dp);
}