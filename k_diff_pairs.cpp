#include<bits/stdc++.h>
using namespace std;

vector<int> a;
int ans = 0;
int solve(int k)
{
    if(a.size()==0 || a.size()==1)
        return 0;
    int n = 0,p = 0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]<0)
        {
            n = max(n,abs(a[i]));
        }
        else
        {
            p = max(p,a[i]);
        }
    }
    vector<int> mp(n+p+1);
    for(int i=0;i<a.size();i++)
    {
        mp[a[i]+n]++;
    }
    vector<bool> vis(n+p+1);
    for(int i=0;i<a.size();i++)
    {
        if(!vis[a[i]+n])
        {
            vis[a[i]+n] = 1;
            if(a[i]+n+k < mp.size())
            {
                if(k)
                {
                    if(mp[a[i]+n+k])
                       ans++;
                }
                else
                {
                    if(mp[a[i]+n]>1)
                        ans++;
                }
                
            }
        }
    }
    return ans;
}
int main()
{
    int n,x,k;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    cin>>k;
    int ans = solve(k);
    cout<<ans;
}