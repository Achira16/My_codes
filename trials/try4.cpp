#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool> (n,0));
        int maxlen = 1,start = 0;
        for(int i=0;i<n;i++)
            dp[i][i] = 1;
        for(int i=0;i<n-1;i++)
        {
            if(s[i] == s[i+1])
            {
                maxlen = 2;
                start = i;
                dp[i][i+1] = 1;
            }
        }
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<=n-k;i++)
            {
                int j = i+k-1;
                if(s[i] == s[j] && dp[i+1][j-1])
                {
                    if(k > maxlen)
                    {
                        maxlen = k;
                        start = i;
                    }
                    dp[i][j] = 1;
                }
            }
        }
        return s.substr(start,maxlen);
    }
int main()
{
    string s;
    cin>>s;
    cout<<longestPalindrome(s);
}