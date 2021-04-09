#include<bits/stdc++.h>
using namespace std;

int search(string& s)
{
    if(s[0] == '0')
        return 0;
    vector<int> dp(s.size(),0);
    dp[0] = 1;
    for(int i=1;i<dp.size();i++)
    {
        if(s[i]!='0')
            dp[i] += dp[i-1];
        if(s[i-1]!='0')
        {
            int a = stoi(s.substr(i-1,2));
            if(a>0 && a<=26)
            {
                if(i-2 < 0)
                    dp[i]+=1;
                else
                    dp[i]+=dp[i-2];
            }
        }
    }
    return dp[s.size()-1];
}
int main()
{
    string s;
    cin>>s;
    cout<<search(s);
}