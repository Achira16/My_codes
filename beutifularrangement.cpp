#include<bits/stdc++.h>
using namespace std;

int ans = 0;
void solve(int i,vector<bool>& vis,int n)
{
    if(i>n)
    {
        ans++;
        return;
    }
    for(int k=1;k<=n;k++)
    {
        if(!vis[k])
        {
            if(k%i == 0 || i%k == 0)
            {
                vis[k] = true;
                solve(i+1,vis,n);
                vis[k] = false;
            }
        }   
    }
}
int main()
{
    int n;
    cin >> n;
    vector<bool> vis(n+1,0);
    for(int i=1;i<=n;i++)
    {
        vis[i] = true;
        solve(2,vis,n);
        vis[i] = false;
    }
    cout<<ans;
}