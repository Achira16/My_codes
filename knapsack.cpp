#include<bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(NULL));
    int n = rand()%20+3;
    int W = rand()%20+4;
    vector<int> weight(n),profit(n);
    for(int i=0;i<n;i++)
    {
        weight[i] = rand()%15+1;
        profit[i] = rand()%100 + 10;
    }
    cout<<n<<" "<<W<<"\n";
    for(auto i:weight){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:profit){
        cout<<i<<" ";
    }
    cout<<endl;
    vector<vector<int>> dp(n+1,vector<int> (W+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(weight[i-1]>j)
                dp[i][j] = dp[i-1][j];
            else{
                dp[i][j] = max(profit[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(auto j:dp[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    int p = dp[n][W];
    int i = n,j = W;
    while(i>=0 && j>=0 && p>0)
    {
        if(p == dp[i][j] && p!=dp[i-1][j] && p!=dp[i][j-1])
        {
            cout<<i<<" ";
            p-= profit[i-1];
            j-=weight[i-1];
            i--;
        }
        else if(p == dp[i][j] && p == dp[i-1][j])
            i--;
        else if(p == dp[i][j] && p == dp[i][j-1])
            j--;
        else
        {
            i--;
        }
    }
    cout<<"\n"<<dp[n][W];
}