#include<bits/stdc++.h>
using namespace std;

int rodCut(int n,vector<int>& profit,vector<int>& dp)
{
    if(n == 1){
        return profit[0];
    }
    if(dp[n])
        return dp[n];
    int rev = profit[n-1];
    for(int i=1;i<n;i++){
        rev = max(rev,profit[i-1] + rodCut(n-i,profit,dp));
    }
    dp[n] = rev;
    return dp[n];
}
int main()
{
    srand(time(NULL));
    int n = rand()%20+4;
    vector<int> profit(n);
    vector<int> dp(n+1);
    vector<int> s(n+1);
    cout<<"Rod length: "<<n<<endl;
    for(int i=0;i<n;i++){
        cin>>profit[i];
    }

    cout<<rodCut(n,profit,dp)<<endl;
    for(int i=0;i<=n;i++){
        dp[i] = 0;
    }
    for(int i=1;i<=n;i++){
        int rev = profit[i-1];
        s[i] = i;
        for(int j=1;j<i;j++){
            if(profit[j-1]+dp[i-j] > rev){
                rev = profit[j-1]+dp[i-j];
                s[i] = j;
            }
        }
        dp[i] = rev;
    }
    cout<<dp[n]<<endl;
    while(n>0){
        cout<<s[n]<<" ";
        n-=s[n];
    }
}