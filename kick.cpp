#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

const int N = 102;
int a[N],ans;
int peeks(int n)
{
    int count = 0;
    for(int i=1;i<n-1;i++)
    {
        if(a[i]>a[i-1] && a[i]>a[i+1])
        {
            count++;
            i++;
        }
    }
    return count;
}
int main()
{
    IOS;
    int T,n;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>n;
        for(int j=0;j<n;j++)
            cin>>a[j];
        ans = peeks(n);
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
}