#include<bits/stdc++.h>
using namespace std;
int find(string& t,string& p)
{
    int n = t.length(),m = p.length(),i,j;
    bool dp[n+1][m+1];
    dp[0][0] = 1;
    for(i=1;i<=n;i++)
        dp[i][0] = 1;
    for(j=1;j<=m;j++)
        dp[0][j] = 0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(p[j-1] == '*')
            {
                dp[i][j] = dp[i][j-1]||dp[i-1][j];
            }
            else if(p[j-1] == t[i-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 0;
        }
    }
    int count = 0;
    for(int k=n;k>=0;k--)
    {
        if(dp[k][m])
        {
            count++;
            int j = m;
            int i = k;
             while(i>0 && j>0)
            {
                if(p[j-1] == '*')
                {
                    if(dp[i-1][j] && dp[i][j-1])
                    {
                        count++;
                        i--;
                    }
                else if(dp[i-1][j])
                    i--;
                else
                    j--;
                }
                else
                {
                    i--;
                    j--;
                }
            }
        }
    }
    return count;
}
int main()
{
    string t,p;
    cin>>t>>p;
    int ans = find(t,p);
    cout<<ans;
}