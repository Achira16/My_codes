#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long 

const int N = 1002;
int a[N];
int latest(int n,int d)
{
    int l,x;
    if(d%a[n-1])
        l = d - d%a[n-1];
    else
        l = d;
    int i = n-2;
    while(i>=0)
    {
        x = l/a[i];
        l = a[i] + (x-1)*a[i];
        i--;
    }
    return l;
}
int32_t main()
{
    IOS;
    int t,n,d,ans;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        for(int j=0;j<n;j++)
            cin>>a[j];
        ans = latest(n,d);
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
}