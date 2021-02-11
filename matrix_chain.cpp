#include<bits/stdc++.h>
using namespace std;

void construct_sol(vector<vector<int>>& s,int i,int j)
{
    if(i == j)
    {
        cout<<"A"<<i;
        return;
    }
    cout<<"(";
    construct_sol(s,i,s[i][j]);
    construct_sol(s,s[i][j]+1,j);
    cout<<")";
}
void solve(vector<int>& dim)
{
    int m = dim.size();
    int n = m-1;
    vector<vector<int>> dp(n,vector<int> (n,0)),s(n+1,vector<int> (n,0));
    for(int l=2;l<=n;l++)
    {
        for(int i=0;i<n-l+1;i++)
        {
            int j=i+l-1;
            int q = INT32_MAX;
            for(int k=i;k<j;k++)
            {
                int t = dp[i][k]+dp[k+1][j]+dim[i]*dim[k+1]*dim[j+1];
                if(t < q)
                {
                    q = t;
                    s[i][j] = k;
                }
            }
            dp[i][j] = q;
        }
    }
    cout<<dp[0][n-1]<<" ";
    construct_sol(s,0,n-1);
}
int main()
{
    int n;
    cin>>n;
    vector<int> dim(n+1);
    for(int i=0;i<=n;i++)
        cin>>dim[i];
    solve(dim);
}