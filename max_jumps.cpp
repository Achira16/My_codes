#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

const int M = 1e4 + 5;
int n,m,v[M],m_j[M];
bool done[M];
int count(int i)
{
    if(i<0 || i>=n)
        return 0;
    if(done[i])
        return m_j[i];
    for(int j=i+1;j<=min(n-1,i+m);j++)
    {
        if(v[j]>=v[i])
            break;
        m_j[i] = max(m_j[i],1+count(j));
    }
    for(int j=i-1;j>=max(0,i-m);j--)
    {
        if(v[j]>=v[i])
            break;
        m_j[i] = max(m_j[i],1+count(j));
    }
    done[i] = 1;
    return m_j[i];
}
int main(){
    // write your code
    IOS;
    int t;
    cin>>t;
    while(t)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
            cin>>v[i];
        memset(m_j,0,sizeof(m_j));
        memset(done,0,sizeof(done));
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans = max(ans,count(i));
        }
        cout<<ans+1<<endl;
        t--;
    }
    return 0;
}