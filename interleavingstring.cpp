#include<bits/stdc++.h>
using namespace std;

bool func(string& s1,string& s2,string& s3)
{
    if(s3.size()!=s1.size()+s2.size())
        return false;
    vector<vector<bool>> dp(s1.size()+1,vector<bool> (s2.size()+1,0));
    dp[0][0] = 1;
    for(int i=1;i<=s2.size();i++)
    {
        if(s3[i-1] == s2[i-1])
            dp[0][i] = dp[0][i-1];
    }
    for(int i=1;i<=s1.size();i++)
    {
        if(s3[i-1] == s1[i-1])
            dp[i][0] = dp[i-1][0];
    }
    for(int i=1;i<=s1.size();i++)
    {
        for(int j=1;j<=s2.size();j++)
        {
            if(s1[i-1] == s3[i+j-1])
                dp[i][j] = dp[i-1][j];
            if(s2[j-1] == s3[i+j-1])
                dp[i][j] = dp[i][j]||dp[i][j-1];
        }
    }
    for(int i=0;i<dp.size();i++)
    {
        for(int j=0;j<dp[0].size();j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[s1.size()][s2.size()];
}
int main()
{
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    cout<<func(s1,s2,s3);
}