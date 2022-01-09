#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector<unordered_map<int,unordered_map<int,ll>>>
// Write any include statements here
ll func(int i,int l1,int l2,vector<int>& C,int M,int N,vec& dp){
  if(i >= M) return 0;
  if(dp[i].find(l1) != dp[i].end()){
    if(dp[i][l1].find(l2) != dp[i][l1].end()) return dp[i][l1][l2];
  }
  ll a1 = min(abs(l1-C[i]),N - abs(l1-C[i]));
  ll a2 = min(abs(l2-C[i]),N - abs(l2-C[i]));
  return dp[i][l1][l2] = min(a1+func(i+1,C[i],l2,C,M,N,dp),a2+func(i+1,l1,C[i],C,M,N,dp));
}

long long getMinCodeEntryTime(int N, int M, vector<int> C) {
  // Write your code here
  vec dp(M);
  return func(0,1,1,C,M,N,dp);
}

int main(){
  // int N,M;
  // cin>>N>>M;
  // vector<int> C(M);
  // for(int i=0;i<M;i++) cin>>C[i];
  // cout<<getMinCodeEntryTime(N,M,C);
  double a1 = 1e9,b1 = 1e9,a2 = 999999999,b2 = 1e9;
  double res1 = a1*log(a1)*b1,res2 = a2*log(a2)*b2;
  if(res1 == res2) cout<<"1";
}