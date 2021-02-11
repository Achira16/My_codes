#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

void actual(vector<vector<int>>& dp,vector<vector<bool>>& check,char ch,string& s)
{
    int n = dp.size();
    for(int i=0;i<n;i++)
    {
        dp[i][i] = 1;
        if(s[i] == ch)
        {
            check[i][i] = 1;
        }
    }
    for(int i=0;i<n-1;i++)
        {
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = 2;
                if(s[i] == ch)
                {
                    check[i][i+1] = 1;
                }
            }
            else
            {
                dp[i][i+1] = 1;
                if(check[i+1][i+1] || check[i][i])
                    check[i][i+1] = 1;
            }
        }
    for(int k=3;k<=n;k++)
        {
            for(int i=0;i<=n-k;i++)
            {
                int j = i+k-1;
                if(s[i] ==  s[j])
                {
                    dp[i][j] = 2 + dp[i+1][j-1];
                    if(s[i] == ch || check[i+1][j-1])
                        check[i][j] = 1;
                }
                else
                {
                    if(dp[i][j-1] > dp[i+1][j])
                    {
                        dp[i][j] = dp[i][j-1];
                        check[i][j] = check[i][j-1];
                    }
                    else if(dp[i+1][j] > dp[i][j-1])
                    {
                        dp[i][j] = dp[i+1][j];
                        check[i][j] = check[i+1][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i][j-1];
                        check[i][j] = (check[i+1][j] | check[i][j-1]);
                    }
                }
            }
        }
}
int solve(string& s,char ch)
{
        if(s.find(ch) == string::npos)
            return 0;
        int n = s.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        vector<vector<bool>> check(n,vector<bool> (n,0));
        vector<vector<int>> dp_actual(n,vector<int> (n,0));
        vector<vector<bool>> check_actual(n,vector<bool> (n,0));
        actual(dp_actual,check_actual,ch,s);
        int maxlen = 0;
        for(int i=0;i<n;i++)
        {
            dp[i][i] = 1;
            if(s[i] == ch)
            {
                check[i][i] = 1;
                maxlen = 1;
            }
        }
        for(int i=0;i<n-1;i++)
        {
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = 2;
                if(s[i] == ch)
                {
                    check[i][i+1] = 1;
                    maxlen = 2;
                }
            }
            else
            {
                dp[i][i+1] = 1;
                if(check[i+1][i+1] || check[i][i])
                    check[i][i+1] = 1;
            }
        }
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<=n-k;i++)
            {
                int j = i+k-1;
                if(s[i] == s[j])
                {
                   if(dp_actual[i+1][j-1] > dp[i+1][j-1])
                   {
                       dp[i][j] = 2+dp_actual[i+1][j-1];
                       if(s[i] == ch || check_actual[i+1][j-1])
                       {
                           check[i][j] = 1;
                           maxlen = max(maxlen,dp[i][j]);
                       }       
                   }
                   else
                   {
                       dp[i][j] = 2+dp[i+1][j-1];
                       if(s[i] == ch || check[i+1][j-1])
                        {
                            check[i][j] = 1;
                            maxlen = max(maxlen,dp[i][j]);
                        }
                   }
                }
                else
                {
                    if(check[i+1][j] || check[i][j-1])
                    {
                        check[i][j] = 1;
                        if(check[i+1][j] && check[i][j-1])
                        {
                            //cout<<i<<j;
                            dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                        }
                        else if(check[i+1][j])
                            dp[i][j] = dp[i+1][j];
                        else    
                            dp[i][j] = dp[i][j-1];
                        maxlen = max(maxlen,dp[i][j]);
                    }
                    else
                    {
                        check[i][j] = 0;
                        dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
                    }
                }
            }
        }
        /* for(int i=0;i<n;i++)
        {
            for(auto j:dp[i])
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }*/
        return maxlen;
     
}
int main()
{
    IOS;
    int t;
    cin>>t;
    while(t)
    {
        string s;
        char ch;
        cin>>ch;
        cin>>s;
        cout<<solve(s,ch)<<endl;
        t--;
    }
}