#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,bool>
#define mod 1000000007

int search(string& s)
{
    if(s[0] == '0')
        return 0;
    vector<int> b1 = {0,9,6,0,0,0,0,0,0,0};
    vector<int> b2 = {2,2,2,2,2,2,2,1,1,1};
    vector<long> dp(s.size(),0);
    if(s[0] == '*')
        dp[0] = 9;
    else
        dp[0] = 1;
    for(int i=1;i<dp.size();i++)
    {
        if(s[i]!='0')
        {
            if(s[i] == '*')
                dp[i] = (dp[i]%mod + (9*dp[i-1]%mod)%mod)%mod;            
            else
                dp[i] = (dp[i]%mod + dp[i-1]%mod)%mod;  
        }
        if(s[i-1]!='0')
        {
            if(s[i]!='*' && s[i-1]!='*')
            {
                int a = stoi(s.substr(i-1,2));
                if(a>0 && a<=26)
                {
                    if(i-2 < 0)
                        dp[i] =  (dp[i]%mod + 1)%mod;
                    else
                        dp[i] = (dp[i]%mod + dp[i-2]%mod)%mod;
                }
            }
            else if(s[i]=='*' && s[i-1]!='*')
            {
                if(i-2 < 0)
                    dp[i] = (dp[i]%mod + b1[s[i-1]-'0']%mod)%mod;
                else
                    dp[i] = (dp[i]%mod + (b1[s[i-1]-'0']%mod*dp[i-2]%mod)%mod)%mod;
            }
            else if(s[i]!='*' && s[i-1]=='*')
            {
                if(i-2<0)
                    dp[i] = (dp[i]%mod + b2[s[i]-'0']%mod)%mod;
                else
                    dp[i] = (dp[i]%mod + (b2[s[i]-'0']%mod*dp[i-2]%mod)%mod)%mod;
            }
            else
            {
                if(i-2<0)
                    dp[i] = (dp[i]%mod +15)%mod;
                else
                    dp[i] = (dp[i]%mod + (15*dp[i-2]%mod)%mod)%mod;
            }
        }
    }
    
    return dp[s.size()-1]%mod;
}
int main()
{
    string s;
    cin>>s;
    cout<<search(s);
}