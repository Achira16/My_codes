#include<bits/stdc++.h>
using namespace std;

string findoverlap(int last,int cur,vector<string>& s)
{
    if(last == -1)
        return s[cur];
    string p = s[last],q = s[cur];
    for(int i=0;i<p.size();i++)
    {
        bool suffix = true;
        int j;
        for(j=0;j < q.size() && i+j < p.size();j++)
        {
            if(p[i+j]!=q[j])
            {
                suffix = false;
                break;
            }
        }
        if(suffix)
        {
            return q.substr(j);
        }
    }
    return q;
}
string func(int last,int mask,int targetmask,vector<string>& s,vector<vector<string>>& dp)
{
    // cout<<mask;
    if(mask == targetmask)
    {
        return "";
    }
    if(dp[last+1][mask]!="")
        return dp[last+1][mask];
    string ans = "";
    for(int i=0;i<s.size();i++)
    {
        if(!(mask & 1<<i))
        {
            string temp = findoverlap(last,i,s)+func(i,mask|(1<<i),targetmask,s,dp);
            if(ans == "" || temp.size()<ans.size())
                ans = temp;
        }
    }
    dp[last+1][mask] = ans;
    return ans;
}
int optimalSuperstring(vector<string> s, int size) 
{
    //Write your code here.
    for(int i=0;i<s.size();i++)
    {
        for(int j=0;j<s.size();j++)
        {
            if(i!=j && s[i].find(s[j])!=string::npos)
                s[j] = "";
        }
    }
    vector<string> updateds;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] != "")
            updateds.push_back(s[i]);
    }
    size = updateds.size();
    int targetmask = (1<<size)-1;
    vector<vector<string>> dp(size+1,vector<string> (targetmask+1,""));
    string ans = func(-1,0,targetmask,s,dp);
    cout<<ans<<" ";
    return ans.size();
}
int main()
{
    int n;
    cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    cout<<optimalSuperstring(s,n);    
}